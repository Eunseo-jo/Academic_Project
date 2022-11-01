#include <iostream>
#include <map>
// #include "search.h"
#include "web_app.h"

int main(int argc, char**argv) {
    if (argc > 1) {
        int port = std::atoi(argv[1]);
        std::string webDir = std::string(argv[2]);
        WebServer<WebApp> server(port, webDir);
        while (true) {
            server.service();
        }
    }
    else {
        std::cout << "Usage: ./build/WebApp 8081 web" << std::endl;
    }

    // // testing FindRobot in search
    // // should go into simulation facade
    // Search searchTest;
    // bool robotFound = searchTest.FindRobot();
    
    // if (robotFound) {
    //     cout << "Robot found!" << endl;
    // }
    // else cout << "Robot was not found." << endl;

    return 0;
}