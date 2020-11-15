//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_WEEKBALANCE_H
#define STORE_WEEKBALANCE_H

#include "DayBalance.h"

class WeekBalance : public Balance
{
private:
    std::list<DayBalance> days;
public:
    WeekBalance();

    //getters & setters
    std::list<DayBalance> getDays();
    bool setDays(std::list<DayBalance> value);
};

#endif //STORE_WEEKBALANCE_H
