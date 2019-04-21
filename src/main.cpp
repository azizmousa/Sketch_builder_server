#include <iostream>

#include <thread>
#include "server/SystemConfiguration.h"
#include "server/Server.h"
#include "server/ServerException.h"
int main(){
    SystemConfiguration::setSystemUIPath("bin/ui.jar");
    SystemConfiguration::setSystemCompilerPath("bin/compiler");
    SystemConfiguration::setSystemEqualizerPath("bin/equalizer");
    SystemConfiguration::setSystemCodeGeneratorPath("bin/ui.jar");

    try{
        Server::setPort("1996");
        Server::connect();
        Server::start();
    }catch(ServerException &e){
        std::cerr << e.what()<< std::endl;
    }
    


    return 0;
}