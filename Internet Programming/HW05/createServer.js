const http = require('http');
const url = require('url');
const fs = require('fs');
const qs = require('querystring');

const port = 9801;
http.createServer(function (req, res) {
  var q = url.parse(req.url, true);
  if (q.pathname === '/') {
    indexPage(req, res);
  }
  else if (q.pathname === '/index.html') {
    indexPage(req, res);
  }
  else if (q.pathname === '/MyContacts.html') {
    contactPage(req, res);
  }
  else if (q.pathname === '/AddContact.html') {
    formPage(req, res);
  }
  else if (q.pathname === '/getContacts') {
    
    let category = q.query.category;
    getContactPage(req, res, category);
  }
  else if (q.pathname === '/postContactEntry') {
    let reqbody = '';
    req.on('data', (data) => {
      reqbody += data;
    });
    req.on('end', () => {
      addContact(req,res,reqbody);
    });
  }

  else{
    res.writeHead(404, {'Content-Type': 'text/html'});
    return res.end("404 Not Found");
  }
}).listen(port);


function indexPage(req, res) {
  fs.readFile('client/index.html', function(err, html) {
    if(err) {
      throw err;
    }
    res.statusCode = 200;
    res.setHeader('Content-type', 'text/html');
    res.write(html);
    res.end();
  });
}

function contactPage(req, res) {
  fs.readFile('client/MyContacts.html', function(err, html) {
    if(err) {
      throw err;
    }
    res.statusCode = 200;
    res.setHeader('Content-type', 'text/html');
    res.write(html);
    res.end();
  });
}

function formPage(req, res) {
  fs.readFile('client/AddContact.html', function(err, html) {
    if(err) {
      throw err;
    }
    res.statusCode = 200;
    res.setHeader('Content-type', 'text/html');
    res.write(html);
    res.end();
  });
}

function getContactPage(req, res, category) {
  fs.readFile('contacts.json', (err, json) => {
    if(err) {
      throw err;
    }
    let parseJson = JSON.parse(json);
    //console.log(parseJson);

    let output = parseJson[category];
    output.sort((a,b) => a.name.localeCompare(b.name));
    //console.log(output);
    let response = {res : output};
    console.log(output);
    
    res.statusCode = 200;
    res.setHeader('Content-type', 'application/json');
    res.write(JSON.stringify(response));
    res.end();
  });
}

function addContact(req,res,body)
{
  let data = qs.parse(body);
  let cat = data.category.toLocaleLowerCase();
  let josnObj = {
    name: data.name,
    location: data.location,
    info: data.info,
    email: data.email,
    website_title: data.website_title,
    url: data.url
  };

  fs.readFile('contacts.json', (err,contect) => {
    if(err) {
      throw err;
    }
    let parseJson = JSON.parse(contect);
    parseJson[cat].push(josnObj);
    fs.writeFile('contacts.json', JSON.stringify(parseJson), (err, result) => {
      if (err) console.log('error', err);
    });

    res.writeHead(302,{
      'Location': '/MyContacts.html'
    });
    res.end()
  });
}