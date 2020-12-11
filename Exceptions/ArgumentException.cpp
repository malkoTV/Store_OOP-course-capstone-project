//
// Created by 1 on 04-Dec-20.
//

#include <iostream>
#include "ArgumentException.h"

ArgumentException::ArgumentException() {
    message = "Invalid argument";
}

std::string ArgumentException::getMessage() {
    return message;
}

void ArgumentException::PrintMessage() {
    std::cout << message << std::endl;
}

std::string ArgumentException::getAMessage() {
    return aMessage;
}