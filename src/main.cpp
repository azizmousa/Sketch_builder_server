#include <iostream>
#include <fstream>

#include "server/SystemConfiguration.h"
#include "server/Server.h"
#include "server/ServerException.h"
int main(){
    std::cout << "server Start:" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::string uiPath, generatorPath, equalizerPath, compilerPath;
    std::ifstream config(".config/binary.config");
    config >> compilerPath;
    config >> equalizerPath;
    config >> generatorPath;
    config >> uiPath;

    config.close();

    SystemConfiguration::setSystemUIPath(uiPath);
    SystemConfiguration::setSystemCompilerPath(compilerPath);
    SystemConfiguration::setSystemEqualizerPath(equalizerPath);
    SystemConfiguration::setSystemCodeGeneratorPath(generatorPath);

    try{
        Server::setPort("1996");
        Server::connect();
        Server::start();
    }catch(ServerException &e){
        std::cerr << e.what()<< std::endl;
    }

    std::cout << "server Stop:" << std::endl;
    std::cout << "--------------------" << std::endl;

    return 0;
}