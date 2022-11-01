# Internet Programming Assignment 04
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
