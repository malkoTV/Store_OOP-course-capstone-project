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
    WeekBalance(DayBalance* days);
    WeekBalance(const WeekBalance& other);
    ~WeekBalance();

    //getters & setters
    DayBalance* getDays();
    bool setDays(DayBalance* value);

    //operators
    DayBalance& operator[](int index);
    operator float() const;

    //methods
    void Table();
    float AvgOrderCount();
    float AvgOrderSum();
    bool Search(std::string str, DayBalance* dayBalance, int& size);

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Search(T num, DayBalance* dayBalance, int& size)
    {
        if(size < 0)
        {
            throw NegSizeException();
        }

        bool flag = false;
        int iter = 0;

        for(int i = 0;  i < W && iter < size; i++)
        {
            if(days[i].Contains(num))
            {
                flag = true;
                dayBalance[iter] = days[i];
                iter++;
            }
        }

        size = iter;
        return flag;
    }
};

#endif //STORE_WEEKBALANCE_H
