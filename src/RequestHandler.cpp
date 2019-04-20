
#include <string>
#include <iostream>
#include <stdlib.h>
#include "server/RequestHandler.h"
#include "server/ServerException.h"
#include "server/StartSystemCommand.h"
#include "server/Command.h"
#include "server/Server.h"
#include "server/ExitCommand.h"
#include "server/CompileCommand.h"


const int EXIT = 1;
const int  START = 2;
const int COMPILE = 3;

RequestHandler::RequestHandler(){
    this->commands.insert({"exit", EXIT});
    this->commands.insert({"start", START});
    this->commands.insert({"compile", COMPILE});
    
}
RequestHandler::~RequestHandler(){
    // delete this->requestedCommand
}


void RequestHandler::mapRequest(){
    std::string command = this->params[0];
    this->params.erase(this->params.begin(), this->params.begin()+1);
    // std::cerr<<"command : "<<command<<"test>>>>>>>>" << this->commands[command] <<std::endl;
    switch (this->commands[command]){
    case EXIT:
        std::cout << "port : " << Server::getPort() << std::endl;
        this->requestedCommand = new ExitCommand();
        // exit(0);
        break;
    case START:
        this->requestedCommand = new StartSystemCommand();
        break;
    case COMPILE:
        this->requestedCommand = new CompileCommand(this->params);
        break;
    
    default:
        std::cerr << "undefined request."<<std::endl;
        this->requestedCommand = NULL;
        break;
    }
}

void RequestHandler::split(){
    if(this->request == "")
        throw ServerException("RequestHandler:: has no request to handle");
    else{
        int currentPos = -1;
        std::string sub;
        int nextSpace;
        do{
            nextSpace = this->request.find(' ', currentPos+1);
            sub = this->request.substr(currentPos+1, nextSpace - currentPos-1);
            std::cerr<<"(" << sub <<")"<< std::endl;
            if(sub != "" || sub != " ")
                this->params.push_back(sub);
            currentPos = nextSpace;
        }while (nextSpace!=-1);
    }
}

void RequestHandler::setRequest(std::string request){
    this->request = request;
    this->split();
    this->mapRequest();
}

Command* RequestHandler::getCommand(){
    return this->requestedCommand;
}