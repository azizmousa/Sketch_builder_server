
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "server/RequestHandler.h"
#include "server/ServerException.h"
#include "server/StartSystemCommand.h"
#include "server/Command.h"
#include "server/Server.h"
#include "server/ExitCommand.h"
#include "server/CompileCommand.h"
#include "server/EqualizeCommand.h"
#include "server/GeneratorCommand.h"

const int EXIT = 1;
const int  START = 2;
const int COMPILE = 3;
const int EQUALIZE = 4;
const int GENERATOR = 5;


RequestHandler::RequestHandler(){
    this->commands.insert({"exit", EXIT});
    this->commands.insert({"start", START});
    this->commands.insert({"compile", COMPILE});
    this->commands.insert({"equalize", EQUALIZE});
    this->commands.insert({"generate", GENERATOR});
    
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
    case EQUALIZE:
        this->requestedCommand = new EqualizeCommand(this->params);
        break;
    case GENERATOR:
        this->requestedCommand = new GeneratorCommand(this->params);
        break;
    default:
        std::cerr << "undefined request."<<std::endl;
        this->requestedCommand = NULL;
        break;
    }
     
}

void RequestHandler::split(){
    if(this->request == ""){
        std::cerr << ("RequestHandler:: has no request to handle") << std::endl;
        this->params.push_back("none");
    }else{
        std::string sub;
        std::stringstream ss(this->request);
        while(!ss.eof()){
            ss >> sub;
            this->params.push_back(sub);
            std::cerr<<"(" << sub <<")"<< std::endl;
        }
    }
}

void RequestHandler::setRequest(std::string request){
    this->request = request;
    std::cerr << "req:: " <<  this->request << std::endl;
    this->split();
    this->mapRequest();
}

Command* RequestHandler::getCommand(){
    return this->requestedCommand;
}