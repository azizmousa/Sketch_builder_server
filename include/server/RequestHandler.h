#ifndef REQUEST_HANDELLER_
#define REQUEST_HANDELLER_

#include <string>
#include <vector>
#include <map>

#include "server/Command.h"


class RequestHandler{
private:

  std::map<std::string, int> commands;

  std::string request;

  std::vector<std::string> params;

  Command *requestedCommand;

  void mapRequest();
  void split();

public:
    RequestHandler();
    ~RequestHandler();

    void setRequest(std::string request);

    Command* getCommand();
};

#endif