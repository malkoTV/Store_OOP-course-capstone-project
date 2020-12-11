//
// Created by 1 on 13-Nov-20.
//

#include "Balance.h"

Balance::Balance() : Showable()
{
    total = 0.0;
}

float Balance::getTotal()
{
    return total;
}
