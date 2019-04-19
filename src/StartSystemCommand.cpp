
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "server/SystemConfiguration.h"
#include "server/StartSystemCommand.h"

void StartSystemCommand::doCommand(){
    // system("./system");
    std::string startCommand = "java -jar " + SystemConfiguration::getSystemUIPath();
    system(startCommand.c_str());
    std::cout << "start command run " << SystemConfiguration::getSystemUIPath()<< std::endl;
}