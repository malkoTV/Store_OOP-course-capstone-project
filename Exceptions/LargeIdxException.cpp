//
// Created by 1 on 04-Dec-20.
//

#include <iostream>
#include "LargeIdxException.h"

LargeIdxException::LargeIdxException(int idx) : IndexingException(idx) {
    aMessage = "Index is out of bounds (more than array length)";
}
