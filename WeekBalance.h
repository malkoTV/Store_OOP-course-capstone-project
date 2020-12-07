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

    //operators
    DayBalance& operator[](int index);

    //methods
    void Table();
    float AvgOrderCount();
    float AvgOrderSum();
    bool Search(std::string str, DayBalance* dayBalance, int& size);
    bool Search(int num, DayBalance* dayBalance, int& size);
};

#endif //STORE_WEEKBALANCE_H
