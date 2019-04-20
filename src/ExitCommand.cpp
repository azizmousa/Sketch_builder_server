
#include "server/ExitCommand.h"
#include "server/Server.h"

ExitCommand::ExitCommand(){}
ExitCommand::~ExitCommand(){}

int ExitCommand::doCommand(){
    Server::disconnect();
    return 0;
}