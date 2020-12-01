//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_WEEKBALANCE_H
#define STORE_WEEKBALANCE_H

#include "DayBalance.h"
#define W 7

class WeekBalance : public Balance
{
private:
    DayBalance* days;
    std::string dayName[W] = {"Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday",
                              "Sunday"};
public:
    //constructors & destructors
    WeekBalance();
    ~WeekBalance();

    //getters & setters
    DayBalance* getDays();
    bool setDays(DayBalance* value);

    //methods
    void Table();
};

#endif //STORE_WEEKBALANCE_H
