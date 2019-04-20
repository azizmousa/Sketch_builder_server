#ifndef COMMAND_
#define COMMAND_

class Command{
public:

    virtual int doCommand() = 0;
    virtual ~Command(){}
};

#endif