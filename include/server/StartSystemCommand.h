#ifndef START_SYSTEM_COMMAND_
#define START_SYSTEM_COMMAND_

#include <thread>
#include "server/Command.h"

class StartSystemCommand: public Command{
private:
    std::thread *commandThread;
public:
    StartSystemCommand();
    ~StartSystemCommand();
    int doCommand();
};

#endif