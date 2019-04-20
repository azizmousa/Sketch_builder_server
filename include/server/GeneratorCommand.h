#ifndef GENERATOR_COMMAND_
#define GENERATOR_COMMAND_

#include <string>
#include <vector>

#include "server/Command.h"

class GeneratorCommand: public Command{
private:
    std::vector<std::string> params;
public:
    GeneratorCommand(std::vector<std::string> params);
    ~GeneratorCommand();
    int doCommand();
};

#endif