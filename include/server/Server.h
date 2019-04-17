#ifndef SERVER_
#define SERVER_

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

class Server{
private:
    char* serverPort;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

public:
    Server(char* serverPort);
    ~Server();

    void connect();
    void start();
    void close();

};
#endif