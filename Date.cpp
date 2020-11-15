//
// Created by 1 on 13-Nov-20.
//

#include <iostream>
#include <iomanip>
#include "Date.h"

//constructors
Date::Date()
{
    day = 1;
    month = 1;
}

//getters & setters
int Date::getDay()
{
    return day;
}

//todo advanced setters for date
bool Date::setDay(int value)
{
    if(value > 0 && value <= 31)
    {
        day = value;
        return true;
    }
    return false;
}

int Date::getMonth()
{
    return month;
}

bool Date::setMonth(int value)
{
    if(value > 0 && value <= 12)
    {
        month = value;
        return true;
    }
    return false;
}

