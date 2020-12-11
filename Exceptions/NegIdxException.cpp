//
// Created by 1 on 04-Dec-20.
//

#include <iostream>
#include "NegIdxException.h"

NegIdxException::NegIdxException(int idx) : IndexingException(idx) {
    aMessage = "Index cannot be negative";
}