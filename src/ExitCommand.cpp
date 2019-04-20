
#include "server/ExitCommand.h"
#include "server/Server.h"

ExitCommand::ExitCommand(){}
ExitCommand::~ExitCommand(){}

void ExitCommand::doCommand(){
    Server::disconnect();
}