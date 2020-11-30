//
// Created by 1 on 13-Nov-20.
//

#include "Seller.h"

Seller::Seller()
{
    lastName = "default";
    firstName = "default";
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
