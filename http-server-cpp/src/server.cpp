#include "server.h"
#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/socket.h>

HTTPServer::HTTPServer(int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server started on port " << port << std::endl;

}

HTTPServer::~HTTPServer() {
    close(serverSocket);
}

void HTTPServer::start() {
    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0){
            perror("Accept failed.");
            continue;
        }
        handleClient(clientSocket);
    }
}

void HTTPServer::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    read(clientSocket, buffer, sizeof(buffer));

    std::string request(buffer);
    std::string response = processRequest(request);

    sendResponse(clientSocket, response);
    close(clientSocket);
}

std::string HTTPServer::processRequest(const std::string &request) {
    std::cout << "Request recieved: " << request << std::endl;

    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/plain\r\n"
           "Content-Length: 12\r\n"
           "\r\n"
           "Hello, World!";
}

void HTTPServer::sendResponse(int clientSocket, const std::string& response){
    send(clientSocket, response.c_str(), response.length(), 0);
}