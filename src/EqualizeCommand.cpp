
#include <iostream>

#include "server/EqualizeCommand.h"

EqualizeCommand::EqualizeCommand(std::vector<std::string> params){
    this->params = params;
}

EqualizeCommand::~EqualizeCommand(){}

int EqualizeCommand::doCommand(){
    std::string command = "./../equalizer/equalizer";
    for(size_t i =0; i< this->params.size(); ++i){
        command += " " + this->params[i];
    }
    std::cout << command << std::endl;
    // 
    int systemRes = system(command.c_str());;
    return systemRes;
}