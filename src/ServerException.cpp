
#include <string>
#include <exception>

#include "server/ServerException.h"


ServerException::ServerException(std::string message){
    this->message = message;
}

ServerException::~ServerException(){}

const char * ServerException::what()const throw(){
    return this->message.c_str();
}