// YOU CAN USE THIS FILE AS REFERENCE FOR SERVER DEVELOPMENT

// Include the express module
const express = require('express');

// Helps in managing user sessions
const session = require('express-session');

// include the mysql module
var mysql = require('mysql');

// Bcrypt library for comparing password hashes
const bcrypt = require('bcrypt');

// helps in extracting the body portion of an incoming request stream
var bodyparser = require('body-parser');

const url = require('url');
const { connect } = require('http2');

// create an express application
const app = express();

// apply the body-parser middleware to all incoming requests
app.use(express.urlencoded({ extended: true }));

// Use express-session
// In-memory session is sufficient for this assignment
app.use(session({
        secret: "csci4131secretkey",
        saveUninitialized: true,
        resave: false
    }
));

const connection = mysql.createConnection({
  host: "cse-mysql-classes-01.cse.umn.edu",
  user: "C4131S22U49",               // replace with the database user provided to you
  password: "2431",           // replace with the database password provided to you
  database: "C4131S22U49",           // replace with the database user provided to you
  port: 3306
});


app.listen(9414, () => console.log('Listening on port 9414!'));

//LOGOUT page
app.get('/logout',function(req,res){
  req.session.destroy(function(err){
    if(err){
       console.log(err);
    }else{
        res.redirect('/');
    }
 });

});
// second route called from browser with localhost:9007/second
// updates the session variable
app.get('/second',function(req,res){
  console.log("Attempting to visit second");
  if (!req.session.value)
  res.send('Session Not Started');
      else {
  console.log("Got to else in second");
  req.session.value += 1;
  var newval = req.session.value;
  res.send('Session value: ' + newval);
}
});
//How would you define an implement a route to destroy() the session
//(that is the same as logout)


// middle ware to serve static files
app.use('/client', express.static(__dirname + '/client'));



app.get('/',function(req, res) {
  res.sendFile(__dirname + '/client/welcome.html');
});

app.get('/home', function(req, res) {

  if(req.session.user){
    console.log("Already login");
    res.sendFile(__dirname + "/client/AllContacts.html")
  }

  else{
    res.redirect('/login'); //else return to login
  }
});

app.get('/MyContacts', function(req, res) {
  
  if(req.session.user){
    res.sendFile(__dirname + '/client/MyContacts.html');
  }
  else{
    res.redirect('/login');
  }

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
  if(req.session.user){
    res.sendFile(__dirname + '/client/AddContact.html');
  }
  else{
    res.redirect('/login');
  }
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
  
  if(req.session.user){
    res.sendFile(__dirname + '/client/AllContacts.html');
  }
  else{
    res.redirect('/login');
  }
  

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
      //res.send(result); 
      res.json(result);
    }
  });
  

});


app.get('/Stocks', function(req, res) {
  if(req.session.user){
    res.sendFile(__dirname + '/client/Stocks.html');
  }
  else{
    res.redirect('/login');
  }
  
});

app.get('/login', function(req, res) {
  res.sendFile(__dirname + '/client/Login.html');
});

app.get('*', function(req, res) {
  // add details
  res.sendStatus(404);
});

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