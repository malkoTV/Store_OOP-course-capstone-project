//
// Created by 1 on 11-Dec-20.
//

#include "NegSizeException.h"

NegSizeException::NegSizeException() : SizeException() {
    message = "Size cannot be a negative number";
}
