/*
TO DO:
-----
READ ALL COMMENTS AND REPLACE VALUES ACCORDINGLY
*/

const mysql = require("mysql");
const bcrypt = require('bcrypt');

const dbCon = mysql.createConnection({
    host: "cse-mysql-classes-01.cse.umn.edu",
    user: "C4131S22U49",               // replace with the database user provided to you
    password: "2431",           // replace with the database password provided to you
    database: "C4131S22U49",           // replace with the database user provided to you
    port: 3306
});

console.log("Attempting database connection");
dbCon.connect(function (err) {
    if (err) {
        throw err;
    }

    console.log("Connected to database!");


    const rowToBeInserted = {
        
        contact_category: 'academic' ,
        contact_name: 'CSE-IT' ,
        contact_location: 'Kenneth' ,
        contact_info: 'CSE' ,
        contact_email: 'cseit@umn.edu' ,
        website_title: 'SE-IT We' ,
        website_url: 'https://cse.umn.edu/cseit' ,  
    };

    console.log("Attempting to insert record into tbl_accounts");
    dbCon.query('INSERT contact_table SET ?', rowToBeInserted, function (err, result) {
        if (err) {
            throw err;
        }
        console.log("Table record inserted!");
    });

    dbCon.end();
});
