//
// Created by 1 on 13-Nov-20.
//

#include "Balance.h"

Balance::Balance()
{

}

float Balance::getTotal()
{
    return total;
}

bool Balance::setTotal(float value)
{
    if(value >= 0)
    {
        total = value;
    }
    return false;
}
