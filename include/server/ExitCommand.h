#ifndef EXIT_COMMAND_
#define EXIT_COMMAND_

#include "server/Command.h"

class ExitCommand: public Command{
private:
    /* data */
public:
    ExitCommand();
    ~ExitCommand();
    void doCommand();
};


#endif