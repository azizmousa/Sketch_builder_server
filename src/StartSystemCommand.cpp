
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <thread>

#include "server/SystemConfiguration.h"
#include "server/StartSystemCommand.h"

StartSystemCommand::StartSystemCommand(){
    this->commandThread = new std::thread;
}

StartSystemCommand::~StartSystemCommand(){
    // delete this->commandThread;
}

void handlCommand(){
    std::string startCommand = "java -jar " + SystemConfiguration::getSystemUIPath();
    int res = system(startCommand.c_str());
    std::cout << "runing " << SystemConfiguration::getSystemUIPath()<< " result = "<<res<< std::endl;
}

void StartSystemCommand::doCommand(){
    *commandThread = std::thread(handlCommand);
    commandThread->detach();
}