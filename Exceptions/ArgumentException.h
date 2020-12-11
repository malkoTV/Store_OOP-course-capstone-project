//
// Created by 1 on 04-Dec-20.
//

#ifndef STORE_ARGUMENTEXCEPTION_H
#define STORE_ARGUMENTEXCEPTION_H

#include <exception>
#include <string>

class ArgumentException : public std::exception {
protected:
    std::string message;
    std::string aMessage;

public:
    //constructors
    ArgumentException();

    //getters & setters
    std::string getMessage();
    std::string  getAMessage();

public:
    //methods
    virtual void PrintMessage();
};


#endif //STORE_ARGUMENTEXCEPTION_H
