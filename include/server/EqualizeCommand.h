#ifndef EQUALIZE_COMMNAD_
#define EQUALIZE_COMMNAD_

#include <string>
#include <vector>

#include "server/Command.h"

class EqualizeCommand: public Command{
private:
    std::vector<std::string> params;
public:
    EqualizeCommand(std::vector<std::string> params);
    ~EqualizeCommand();
    int doCommand();
};

#endif