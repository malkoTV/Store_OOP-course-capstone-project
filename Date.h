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
    Date(int day, int month);

    //getters & setters
    int getDay();
    bool setDay(int value);

    int getMonth();
    bool setMonth(int value);

    //operators
    std::string operator+(const std::string& str) const;
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
    Date operator++();
    Date operator--();

    operator std::string() const;

    //methods
};

#endif //STORE_DATE_H
