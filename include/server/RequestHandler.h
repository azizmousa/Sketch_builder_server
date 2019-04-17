#ifndef REQUEST_HANDELLER_
#define REQUEST_HANDELLER_

#include <string>

#include "server/Command.h"

class RequestHandler{
private:
  std::string request;
public:
    RequestHandler(std::string request);
    ~RequestHandler();

    void mapRequest();
    Command getCommand();
};

#endif