
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

#include "server/GeneratorCommand.h"
#include "server/SystemConfiguration.h"
#include "server/Files.h"

GeneratorCommand::GeneratorCommand(std::vector<std::string> params){
    this->params = params;
}
GeneratorCommand::~GeneratorCommand(){}

int GeneratorCommand::doCommand(){
    std::string command = "java -jar " + SystemConfiguration::getSystemCodeGeneratorPath() + Files::slash();
    for(size_t i =0; i< this->params.size(); ++i){
        command += " " + this->params[i];
    }
    std::cout << command << std::endl;
    // 
    int systemRes = system(command.c_str());;
    return systemRes;
}
