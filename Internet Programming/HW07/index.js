const express = require('express');
const session = require('express-session');
var mysql = require('mysql');
const bcrypt = require('bcrypt');
var bodyparser = require('body-parser');
var fs = require("fs");
var xml2js = require('xml2js');

var parser = new xml2js.Parser();
var dbhost, dbuser, dbpwd, db, dbport;
var connection;

fs.readFile(__dirname + '/dbconfig.xml', function(err, data) {
	if (err) throw err;
    parser.parseString(data, function (err, result) {
		if (err) throw err;

    dbhost = result.dbconfig.host[0];
    dbuser= result.dbconfig.user[0];
    dbpwd = result.dbconfig.password[0]; 
    db = result.dbconfig.database[0]; 
    dbport = result.dbconfig.port[0];

    connection = mysql.createConnection({
      host: dbhost,
      user: dbuser,        
      password: dbpwd,     
      database: db,  
      port: dbport
    });
	});
  
});

const url = require('url');
const { connect } = require('http2');

const app = express();
app.use(express.urlencoded({ extended: true }));
app.use(session({
        secret: "csci4131secretkey",
        saveUninitialized: true,
        resave: false
    }
));
//
//mysql -uC4131S22U49 -hcse-mysql-classes-01.cse.umn.edu -P3306 -p C4131S22U49


app.listen(9414, () => console.log('Listening on port 9414!'));

//LOGOUT page
app.get('/logout',function(req,res){
  req.session.destroy(function(err){
    if(err){  console.log(err);
    }else{ res.redirect('/'); }
 });
});

app.use('/client', express.static(__dirname + '/client'));

app.get('/',function(req, res) {
  res.sendFile(__dirname + '/client/welcome.html');
});

app.get('/home', function(req, res) {

  if(req.session.user){
    res.sendFile(__dirname + "/client/AllContacts.html");
  }
  else{ res.redirect('/login');}
});
//hw7
app.get('/Admin', function(req, res) {

  if(req.session.user){
    res.sendFile(__dirname + "/client/Admin.html");
  }
  else{ res.redirect('/login');}
  
});

app.get('/MyContacts', function(req, res) {
  
  if(req.session.user){ res.sendFile(__dirname + '/client/MyContacts.html'); }
  else{ res.redirect('/login');}
});

app.get('/getContacts', function(req, res) {
  let category = req.query.category;
  var query = "SELECT * FROM contact_table WHERE contact_category = '" +  category
  +"' ORDER BY contact_name ASC";

  connection.query(query, function(err,result,fields) 
  {
    if (err) throw err;
    result = JSON.parse(JSON.stringify(result));
    if (result.length == 0) console.log("No entries in table");
    else {
      console.log(result);
      res.send(result); 
    }
  });
});

app.get('/AddContact', function(req, res) {
  if(req.session.user){ res.sendFile(__dirname + '/client/AddContact.html'); }
  else{ res.redirect('/login');}
});

//POST addContact
app.post('/postContactEntry', function(req, res) {
  var contact_category = req.body.contact_category;
  var contact_name = req.body.contact_name;
  var contact_location = req.body.contact_location;
  var contact_info = req.body.contact_info;
  var contact_email = req.body.contact_email;
  var website_title = req.body.website_title;
  var contact_url = req.body.contact_url;

  var sql =  'INSERT INTO contact_table (contact_category, contact_name, contact_location, contact_info, contact_email,website_title,website_url) VALUES (' + '"' + contact_category + '"' + 
  ',' + '"' + contact_name + '"' + 
  ',' + '"' + contact_location + '"' + 
  ',' + '"' + contact_info + '"' + 
  ',' + '"' + contact_email + '"' + 
  ',' + '"' + website_title + '"' + ',' + '"' + contact_url + '"' + ')';

  connection.query(sql, function(err, result) {
    if (err) throw err;
    console.log('Added in SQL table');
    res.redirect(302, '/AllContact');
  });
});

app.get('/AllContact', function(req, res) {
  if(req.session.user){ res.sendFile(__dirname + '/client/AllContacts.html'); }
  else{ res.redirect('/login');}
});

app.get('/GetAllContact', function(req, res) {

  var query = "SELECT * FROM contact_table ORDER BY contact_category ASC";
  connection.query(query, function(err,result,fields) 
  {
    if (err) throw err;
    result = JSON.parse(JSON.stringify(result));
    if (result.length == 0) console.log("No entries in table");
    else {
      console.log(result);
      res.json(result);
    }
  });
});

app.get('/Stocks', function(req, res) {
  if(req.session.user){
    res.sendFile(__dirname + '/client/Stocks.html');
  }
  else{ res.redirect('/login');}
});

app.get('/login', function(req, res) { 
  res.sendFile(__dirname + '/client/Login.html'); });

app.post('/getlogin', function(req, res) {
  
  var loginInfo = req.body;
  var login = loginInfo.login;
  var pwd = loginInfo.password;

  var query = "SELECT * FROM tbl_accounts WHERE acc_login = '"+ login + "';";
  
  connection.query(query, function(error, rows) {
    if (error) throw error;
    var rows = JSON.parse(JSON.stringify(rows));
  
    if (rows.length >=1){ 
      if ( bcrypt.compareSync(pwd, rows[0].acc_password )) {
      //success, set the session, return success
        req.session.user = login;
        res.json({status: 'success'}); 
      }
      else {res.json({status: 'fail'}); }
      
      }
  else {res.json({status: 'fail'}); console.log("Login fail");}
  });

});

//HW07
app.get('/userLogin', function(req, res) { 
  
  res.send({login: req.session.user});

});

app.get('/getListOfUsers', function(req, res) { 
  console.log("Server getListOfUsers ");
  
  var query = "SELECT * FROM tbl_accounts";
  var objArray = [];
  console.log("getListOfUsers");
  connection.query(query, function(err,results,fields) 
  {
    console.log("db connected");
    if (err) throw err;
    results = JSON.parse(JSON.stringify(results));
    if (results.length == 0) console.log("Empty table");
    else {
      console.log(results);
      for (var i in results){
        var obj = { 
          id: results[i].acc_id,
          name: results[i].acc_name,
          login: results[i].acc_login,
          password: results[i].acc_password
        };
        objArray.push(obj);
      }
      res.json(objArray);
    }
  });
  
});

app.post('/switchUser', function(req, res) { 
  
  //res.send({login: req.session.user});
  //

  if (req.session.user){ //If session id (user) is set
  var loginInfo = req.body;
  var login = loginInfo.login;
  var query = "SELECT * FROM tbl_accounts WHERE acc_login = '"+ login + "';";
  
  if ( login != req.session.user)
  {
    connection.query(query, function(error, result) {
      if (error) throw error;
      result = JSON.parse(JSON.stringify(result));
      if (result.length >= 1) 
      {
        req.session.user = login;
        res.json({status: 'success'}); 
      }
      else {
        console.log("switch fail");
        res.json({status: 'fail'});
      }
    });
  }
  else { res.json({status: 'fail'}); console.log("Already Login this user")}
}

  else { res.redirect(302, '/login'); console.log("switch fail");}   
});

app.post('/addUser', function(req, res) { //DONE

  var account_name = req.body.name;
  var account_login = req.body.login;
  var account_pwd = req.body.password;
  //Hashpassword
  const saltRounds = 10;
  const myPlaintextPassword = account_pwd;
  const passwordHash = bcrypt.hashSync(myPlaintextPassword, saltRounds);

  var query = "SELECT * FROM tbl_accounts WHERE acc_login = '" + account_login + "'";

  var sql =  "INSERT INTO tbl_accounts (acc_name, acc_login, acc_password) VALUES ('"  + account_name + "', '" + account_login + "', '" + passwordHash + "')";

if (req.session.user){
  connection.query(query, function(err, result) {
    if (err) throw err;
    if (result.length == 0){ 
      //insert the name, login and password of the new user
      connection.query(sql, function(err, results) {
        if (err) throw err;
        else{console.log('Added in SQL table');}
      });

      connection.query(query, function(err, results) {
        if (err) throw err;
        else{
          res.send({flag: true, id: results[0].acc_id});
        }
      });
       
    }
    else {res.send({flag:false}); console.log('login exists');} //login already exists
  });
}
else res.redirect(302, '/login');
});

app.post('/updateUser', function(req, res) { //DONE

var account_id = req.body.id;
var account_name = req.body.name;
var account_login = req.body.login;
var account_pwd = req.body.password;

//Hashpassword
const saltRounds = 10;
const myPlaintextPassword = account_pwd;
const passwordHash = bcrypt.hashSync(myPlaintextPassword, saltRounds);

// check the login id exists only for the id associated with the login
var query = "SELECT * FROM tbl_accounts where acc_login = '" + account_login + "' and acc_id != '" + account_id + "'";

if (req.session.user){ //If session id (user) is set
connection.query(query, function(error, rows) {
  if (error) throw error;
  var rows = JSON.parse(JSON.stringify(rows));

  if (rows.length == 0){ //then login id does not exist for another account
    if ( account_pwd != ""){

      var sql = "UPDATE tbl_accounts SET acc_name = '" + account_name + "', acc_login = '"+ account_login + "', acc_password = '" + passwordHash + "'WHERE acc_id = '" + account_id + "'";

      connection.query(sql, function(error, rows) {
        if (error) throw error;
        console.log("Update name, login, password")
        res.send({flag:true});
      });
    }
    else {
      //Otherwise Update name, login where accd_id = req.body.id
      var sql = "UPDATE tbl_accounts SET acc_name = '" + account_name + "', acc_login = '"+ account_login + "'WHERE acc_id = '" + account_id + "'";

      connection.query(sql, function(error, rows) {
        if (error) throw error;
        console.log("Update name and login")
        res.send({flag:true});
      });
    }
  }
  else //does not exist for another account
  {
    res.send({flag:false}); //login already exsits
    console.log("Update Fail");
  }
});
}
else { res.redirect(302, '/login'); console.log("Update fail");} 

});

app.post('/deleteUser', function(req, res) { //check login != user.

if (req.session.user){ //If session id (user) is set
var loginInfo = req.body;
  var login = loginInfo.login;
  var query = "DELETE FROM tbl_accounts WHERE acc_login = '"+ login + "';";
  if ( login != req.session.user)
  {
    connection.query(query, function(error, rows) {
      if (error) throw error;
      res.send({flag:true});
    });
  }
  else {res.send({flag:false}); console.log("This login is used by another user")}
}
else {res.redirect(302, '/login'); console.log("Delete Fail");}
});

app.get('*', function(req, res) {
  res.sendStatus(404);
});