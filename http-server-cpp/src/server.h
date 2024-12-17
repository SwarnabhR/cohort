#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <netinet/in.h>

class HTTPServer {
    public:
        HTTPServer(int port);
        ~HTTPServer();
        void start();
    private:
        int serverSocket;
        sockaddr_in serverAddr;

        void handleClient(int clientSocket);
        std::string processRequest(const std::string &request);
        void sendResponse(int clientSocket, const std::string &response);
};

#endif