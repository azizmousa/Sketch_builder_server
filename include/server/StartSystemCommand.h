#ifndef START_SYSTEM_COMMAND_
#define START_SYSTEM_COMMAND_

#include "server/Command.h"

struct StartSystemCommand: public Command{
    void doCommand();
};

#endif