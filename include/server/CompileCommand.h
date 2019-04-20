#ifndef COMPILE_COMMAND_
#define COMPILE_COMMAND_

#include <string>
#include <vector>

#include "server/Command.h"

class CompileCommand: public Command{
private:
    std::vector<std::string> params;
public:
    CompileCommand(std::vector<std::string> params);
    ~CompileCommand();
    int doCommand();
};

#endif