#ifndef SERVER_EXCEPTION_
#define SERVER_EXCEPTION_

#include <string>
#include <exception>

class ServerException: public std::exception{
private:
    std::string message;
public:
    ServerException(std::string message);
    ~ServerException();
    virtual const char *what()const throw();
};

#endif