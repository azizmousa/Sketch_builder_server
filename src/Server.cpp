
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <thread>

#include "server/Server.h"
#include "server/ServerException.h"
#include "server/RequestHandler.h"
#include "server/Command.h"



Server::Server(std::string serverPort){
    this->serverPort = serverPort;
}

Server::~Server(){
    this->disconnect();
}


void Server::connect(){
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd < 0) 
       throw ServerException("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    this->portno = atoi(this->serverPort.c_str());
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_addr.s_addr = INADDR_ANY;
    this->serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             throw ServerException("ERROR on binding");
}

void Server::start(){
    while(1){
        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
        if (newsockfd < 0) 
            throw ServerException("ERROR on accept");
        bzero(buffer,256);
        this->n = read(newsockfd,buffer,255);
        if (n < 0) 
            throw ServerException("ERROR reading from socket");
        handlRequest(std::string(buffer));
        printf("Here is the message: %s\n",buffer);
        this->sendMessageToClient("I got your message");
        if (this->n < 0) 
            throw ServerException("ERROR writing to socket");
        
    }
}

void Server::disconnect(){
    close(this->newsockfd);
    close(this->sockfd);
}

void Server::sendMessageToClient(std::string message){
    this->n = write(newsockfd, message.c_str(),18);
}

void Server::handlRequest(std::string request){
    RequestHandler *requestHandler = new RequestHandler();
    requestHandler->setRequest(request);
    Command *command = requestHandler->getCommand();
    command->doCommand();
    
    delete command;
    delete requestHandler;
}