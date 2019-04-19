#ifndef SERVER_
#define SERVER_

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <vector>

class Server{
private:
    std::string serverPort;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    void handlRequest(std::string request);
public:
    Server(std::string serverPort);
    ~Server();

    void connect();
    void start();
    void disconnect();
    void sendMessageToClient(std::string message);
};
#endif