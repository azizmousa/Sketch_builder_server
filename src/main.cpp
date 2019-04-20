#include <iostream>

#include <thread>
#include "server/SystemConfiguration.h"
#include "server/Server.h"

int main(){
    SystemConfiguration::setSystemUIPath("../UI/ui.jar");
    SystemConfiguration::setSystemCompilerPath("../compiler/compiler");
    SystemConfiguration::setSystemEqualizerPath("../equalizer/equalizer");
    SystemConfiguration::setSystemCodeGeneratorPath("../UI/ui.jar");

    Server::setPort("1996");
    Server::connect();
    Server::start();


    return 0;
}