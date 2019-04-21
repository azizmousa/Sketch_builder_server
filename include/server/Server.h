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
    Server();
    ~Server();
    static std::string serverPort;
    static int sockfd, newsockfd, portno;
    static socklen_t clilen;
    static struct sockaddr_in serv_addr, cli_addr;
    static int n;
    static bool listening;

    static int handlRequest(std::string request);
public:
    
    static void setPort(std::string serverPort);
    static std::string getPort();
    static void connect();
    static void start();
    static void disconnect();
    static void sendMessageToClient(std::string message);
};
#endif