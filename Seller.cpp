//
// Created by 1 on 13-Nov-20.
//

#include "Seller.h"

Seller::Seller()
{

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
    return false;
}
