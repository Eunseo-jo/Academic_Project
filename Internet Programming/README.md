# CSCI 4131 - Internet Programming Assignment
This contains code assignments for the University of Minnesota Computer Science class - CSCI 4131, which I took Spring 2022 semester.

## Internet Programming Assignment 03

add Google Maps to the functionality Contacts and Form Web pages through homework 2
enhance the styling of Widgets Page (CSS / HTML)

### objective
-  Continue to develop JavaScript skills
-  Introduce the Google Maps JavaScript application programming interface (API), the Google Places JavaScript library, the Google Maps Directions Service, and geolocation. 

### My Contatcts page contains
-  dynamically mark the addresses of contacts specified in the contacts web page on an embedded Google map.
-  search for specific places near current location and display them on the map
-  to calculate directions and display a route between selected location and selected destination (which is the location of one the people on contacts list) on Google map via various modes of transportation.
-  calculate and display the distance of a place to a target location

### MyForm page contains
-  Include GoogleMap
-  A location on the Google Map is selected, it will automatically populate the address field of the form.

### MyWidgets page contains
-  Youtube, Twiter widgets
-  Random password generation and password strength checker

## Internet Programming Assignment 04
- build a small subset of an HTTP server in Python 3
- using Python 3 and TCP sockets, program some of the basic functionality of an HTTP (Web) server. 
- When a web client (such as Google Chrome) connects to a web server (such as https://www.google.com) the data that is exchanged between them (e.g., HTTP messages, HTML, CSS, JavaScript, pictures, audio, video, etc.) is transmitted using the Hyper-Text Transfer Protocol. 


- An HTTP client connects to the HTTP-server and sends an HTTP request message requesting a resource to the HTTP server.
- The request can be of type HEAD, GET, POST, etc.
- The server parses the request header fields.
- For a GET request, the server identifies the requested resource (e.g., an HTML file) and checks if the resource exists and if it can access it. 
- For a GET request, the server identifies the requested resource (e.g., an HTML file) and checks if the resource exists and if it can access it. 
- If the requested resource is found and is accessible, the HTTP server reads in the resource and builds a response message. 
- If the resource requested by the HTML client is not found, then the HTTP Server composes and sends a response message with an error response status code to the HTTP client (e.g., a browser).

## Internet Programming Assignment 05

+ For this assignment, use JavaScript for server-side scripting. Essentially, instead of writing the server code in Python in HW4, develop a basic web-server using JavaScript. 

+ Use either JavaScript or jQuery to request data using Asynchronous JavaScript and XML (AJAX) and manipulate the Document Object Model of the Webpage making the AJAX request

+ Using AJAX on the client-side to create asynchronous web applications, requ+ est data from the server, receive data from the server and update the web page without reloading the entire web-page.

## Internet Programming Assignment 06

Develop a basic website using Express

- routing: a way to map URLs and http verbs to code paths
- Easy methods for parsing http requests and building http responses


- The login page uses AJAX to send user credentials (id and password) to the server, and the server correctly redirects the browser to the “My Contacts” page after successful login validation by the server.

- If server login validation fails, an error message is displayed on the "Login" page and the browser displays the login page and an error message.

- Get the list of information from the server (which the server gets from the database)

- Correctly and dynamically added to the table, and correctly displayed in the user’s browser.

## Internet Programming Assignment 07

+ Add a new user administration page with user management features that enable you to add new users, delete users, or update information on existing users of your website

+ Compose and submit delete and update SQL queries to the MySQL database from your node.js/Express server with information gathered from the user via HTML pages.

+ Using an XML file to save the database configuration from enabling flexibility and increasing security read the configuration information from the XML file, and that information connected to MySQL database.
