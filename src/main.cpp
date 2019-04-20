#include <iostream>

#include <thread>
#include "server/SystemConfiguration.h"
#include "server/Server.h"
#include "server/ServerException.h"
int main(){
    SystemConfiguration::setSystemUIPath("../UI/ui.jar");
    SystemConfiguration::setSystemCompilerPath("../compiler/compiler");
    SystemConfiguration::setSystemEqualizerPath("../equalizer/equalizer");
    SystemConfiguration::setSystemCodeGeneratorPath("../UI/ui.jar");

    try{
        Server::setPort("1996");
        Server::connect();
        Server::start();
    }catch(ServerException &e){
        std::cerr << e.what()<< std::endl;
    }
    


    return 0;
}