//
// Created by 1 on 13-Nov-20.
//

#include "WeekBalance.h"

WeekBalance::WeekBalance() : Balance()
{

}

std::list<DayBalance> WeekBalance::getDays()
{
    return days;
}

bool WeekBalance::setDays(std::list<DayBalance> value)
{
    days = value;
    return true;
}
