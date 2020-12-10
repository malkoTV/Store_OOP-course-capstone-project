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
    this->day = day;
    this->month = month;
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

std::string Date::operator+(const std::string &str) const
{
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

    return str + strD + "." + strM;
}

bool Date::operator==(const Date &other) const
{
    return day == other.day && month == other.month;
}

bool Date::operator!=(const Date &other) const
{
    return day != other.day || month != other.month;
}

bool Date::operator<(const Date &other) const
{
    if(month < other.month)
    {
        return true;
    }
    else if(month == month)
    {
        if(day < other.day)
        {
            return true;
        }
    }
    return false;
}

bool Date::operator>(const Date &other) const
{
    if(month > other.month)
    {
        return true;
    }
    else if(month == month)
    {
        if(day > other.day)
        {
            return true;
        }
    }
    return false;
}

bool Date::operator<=(const Date &other) const
{
    if(month < other.month)
    {
        return true;
    }
    else if(month == month)
    {
        if(day <= other.day)
        {
            return true;
        }
    }
    return false;
}

bool Date::operator>=(const Date &other) const
{
    if(month > other.month)
    {
        return true;
    }
    else if(month == month)
    {
        if(day >= other.day)
        {
            return true;
        }
    }
    return false;
}

Date Date::operator++()
{
    //todo advanced checking
    day++;
    if(day > 31)
    {
        month++;
        if(month > 12)
        {
            month = 1;
        }
        day = 1;
    }
    return Date(day, month);
}

Date Date::operator--()
{
    day--;
    if(day < 1)
    {
        month--;
        if(month < 1)
        {
            month = 12;
        }
        day = 31;
    }
    return Date(day, month);
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
    return (os << std::string(obj));
}

