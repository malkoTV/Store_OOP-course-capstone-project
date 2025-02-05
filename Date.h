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
    Date(const Date& other);

    //getters & setters
    int getDay();
    bool setDay(int value);

    int getMonth();
    bool setMonth(int value);

    //operators
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;

    operator std::string() const;

    //methods
    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Contains(T var)
    {
        bool flag = false;
        if(var == day || var == month)
        {
            flag = true;
        }

        return flag;
    }

private:
    void Update();
};

std::ostream& operator<<(std::ostream& os, const Date& obj);

#endif //STORE_DATE_H
