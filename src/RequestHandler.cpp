
#include <string>
#include <iostream>

#include "server/RequestHandler.h"
#include "server/ServerException.h"
#include "server/StartSystemCommand.h"
#include "server/Command.h"

const int  start = 1;
#define start_str "start"

RequestHandler::RequestHandler(){
    this->commands.insert({"start", start});
    
}
RequestHandler::~RequestHandler(){}


void RequestHandler::mapRequest(){
    std::string command = this->params[0];
    // std::cerr<<"command : "<<command<<"test>>>>>>>>" << this->commands[command] <<std::endl;
    switch (this->commands[command]){
    case start:
        this->requestedCommand = new StartSystemCommand();
        break;
    
    default:
        throw ServerException("RequestHandler:: command " + std::string(command) + " not found" );
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
            // std::cerr << sub << std::endl;
            this->params.push_back(sub);
            currentPos = nextSpace;
        }while (nextSpace!=-1);
        // sub = this->request.substr(currentPos, nextSpace - currentPos);
        // this->params.push_back(sub);
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