//
// Created by 1 on 13-Nov-20.
//

#include <iostream>
#include "Seller.h"

Seller::Seller()
{
    lastName = "default";
    firstName = "default";
    age = 18;
}

std::string Seller::getLastName()
{
    return lastName;
}

bool Seller::setLastName(std::string value)
{
    if(value != "")
    {
        lastName = value;
        return true;
    }
    else
    {
        lastName = "default";
        return false;
    }
}

std::string Seller::getFirstName()
{
    return firstName;
}

bool Seller::setFirstName(std::string value)
{
    if(value != "")
    {
        firstName = value;
        return true;
    }
    else
    {
        firstName = "default";
        return false;
    }
}

int Seller::getAge()
{
    return age;
}

bool Seller::setAge(int value)
{
    if(value >= 18 && value < 120)
    {
        age = value;
        return true;
    }
    else
    {
        age = 18;
        return false;
    }
}

Seller::operator std::string() const
{
    return lastName + " " + firstName;
}

bool Seller::operator==(const Seller &other) const
{
    return (firstName == other.firstName) && (lastName == other.lastName) && (age == other.age);
}

bool Seller::operator!=(const Seller &other) const
{
    return (firstName != other.firstName) || (lastName != other.lastName) || (age != other.age);
}

bool Seller::Contains(std::string str)
{
    bool flag = false;

    if(str == lastName || str == firstName)
    {
        flag = true;
    }

    return flag;
}

std::ostream& operator<<(std::ostream& os, const Seller& obj)
{
    return (os << std::string(obj));
}
