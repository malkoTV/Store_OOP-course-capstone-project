//
// Created by 1 on 11-Dec-20.
//

#include "ZeroSizeException.h"

ZeroSizeException::ZeroSizeException() : SizeException() {
    aMessage = "Size must not be zero";
}
