
#include <iostream>

#include "server/EqualizeCommand.h"
#include "server/SystemConfiguration.h"
#include "server/Files.h"

EqualizeCommand::EqualizeCommand(std::vector<std::string> params){
    this->params = params;
}

EqualizeCommand::~EqualizeCommand(){}

int EqualizeCommand::doCommand(){
    std::string command = SystemConfiguration::getSystemEqualizerPath();
    for(size_t i =0; i< this->params.size(); ++i){
        command += " " + this->params[i];
        // std::cout << "P:(" << this->params[i]<< ")" <<std::endl;
    }
    std::cout << command << std::endl;
    // 
    int systemRes = system(command.c_str());;
    return systemRes;
}