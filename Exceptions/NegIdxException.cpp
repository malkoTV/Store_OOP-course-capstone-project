//
// Created by 1 on 04-Dec-20.
//

#include <iostream>
#include "NegIdxException.h"

NegIdxException::NegIdxException() : IndexingException() {
    aMessage = "Index cannot be negative";
}

NegIdxException::NegIdxException(int idx) : IndexingException(idx) {
    aMessage = "Index cannot be negative";
}

void NegIdxException::PrintMessage() {
    IndexingException::PrintMessage();
    std::cout << aMessage << std::endl;
}
