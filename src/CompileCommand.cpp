
#include <string>
#include <vector>
#include <stdlib.h>

#include "server/CompileCommand.h"


CompileCommand::CompileCommand(std::vector<std::string> params){
    this->params = params;
}
CompileCommand::~CompileCommand(){}

void CompileCommand::doCommand(){
    std::string command = "./../compiler/compiler";
    for(size_t i =0; i< this->params.size(); ++i)
        command += " " + this->params[i];
    system(command.c_str());
}