//
// Created by 1 on 04-Dec-20.
//

#include <iostream>
#include "IndexingException.h"

IndexingException::IndexingException() : ArgumentException() {
    message = "Invalid index";
}

IndexingException::IndexingException(int index) : ArgumentException() {
    message = "Invalid index";
    this->index = index;
}

int IndexingException::getIndex() {
    return index;
}

void IndexingException::PrintMessage()
{
    std::cout << message << std::endl;
    std::cout << "No element found at location " << index << std::endl;
}

std::string IndexingException::getAMessage() {
    return aMessage;
}
