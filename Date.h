//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_DATE_H
#define STORE_DATE_H

#include <iostream>

class Date
{
private:
    int day;
    int month;
public:
    Date();

    //getters & setters
    int getDay();
    bool setDay(int value);

    int getMonth();
    bool setMonth(int value);

    //operators
    operator std::string() const;

    //methods
};

#endif //STORE_DATE_H
