
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <thread>

#include "server/SystemConfiguration.h"
#include "server/StartSystemCommand.h"

void handlCommand(std::thread * th){
    std::string startCommand = "java -jar " + SystemConfiguration::getSystemUIPath();
    int res = system(startCommand.c_str());
    std::cout << "runing " << SystemConfiguration::getSystemUIPath()<< " result = "<<res<< std::endl;
    delete th;
}

void StartSystemCommand::doCommand(){
    // system("./system");
    std::thread *commandThread = new std::thread;
    *commandThread = std::thread(handlCommand, commandThread);
    
}