#ifndef COMMAND_
#define COMMAND_

class Command{
public:

    virtual void doCommand() = 0;
    virtual ~Command(){}
};

#endif