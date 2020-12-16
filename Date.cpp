//
// Created by 1 on 13-Nov-20.
//

#include <string>
#include "Date.h"

//constructors
Date::Date()
{
    day = 1;
    month = 1;
}

Date::Date(int day, int month)
{
    if(day > 0 && day <= 31)
    {
        this->day = day;
    }

    if(month > 0 && month <= 12)
    {
        this->month = month;
    }

    Update();
}

Date::Date(const Date &other)
{
    day = other.day;
    month = other.month;
}

//getters & setters
int Date::getDay()
{
    return day;
}

bool Date::setDay(int value)
{
    if(value > 0 && value <= 31)
    {
        day = value;
        Update();
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
        Update();
        return true;
    }
    return false;
}

Date::operator std::string() const {
    std::string strM = std::to_string(month);
    if(month < 10)
    {
        strM = "0" + strM;
    }

    std::string strD = std::to_string(day);
    if(day < 10)
    {
        strD = "0" + strD;
    }

    return strD + "." + strM;
}

bool Date::operator==(const Date &other) const
{
    return day == other.day && month == other.month;
}

bool Date::operator!=(const Date &other) const
{
    return day != other.day || month != other.month;
}

void Date::Update()
{
    if(month == 2)
    {
        if(day > 28)
        {
            day = 28;
        }
    }
    else
    {
        if(month % 2 == 0)
        {
            if(day > 30)
            {
                day = 30;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
    return (os << std::string(obj));
}

