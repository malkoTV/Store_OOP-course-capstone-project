//
// Created by 1 on 13-Nov-20.
//

#include <string>
#include "Item.h"

//constructors
Item::Item()
{
    name = "default";
    type = individually;
    price = 0.0f;
}

Item::Item(std::string name, ItemType type, float price)
{
    if(name != "")
    {
        this->name = name;
    }
    else
    {
        this->name = "default";
    }

    this->type = type;

    if(price > 0)
    {
        this->price = price;
    }
    else
    {
        price = 0.0;
    }
}

//getters & setters
std::string Item::getName()
{
    return name;
}

bool Item::setName(std::string value)
{
    //todo add regex checking - no special characters
    if(value != "")
    {
        name = value;
        return true;
    }
    else
    {
        name = "default";
        return false;
    }
}

ItemType Item::getType()
{
    return type;
}

bool Item::setType(ItemType value)
{
    type = value;
    return true;
}

float Item::getPrice()
{
    return price;
}

bool Item::setPrice(float value)
{
    if(value > 0)
    {
        price = value;
        return true;
    }
    else
    {
        price = 1.0;
        return false;
    }
}

Item::operator std::string() const
{
    return name;
}

bool Item::operator==(const Item &other) const
{
    return (name == other.name) && (type == other.type)
    && (price == other.price);
}

bool Item::operator!=(const Item &other) const
{
    return (name != other.name) || (type != other.type)
           || (price != other.price);
}

bool Item::Contains(std::string str)
{
    bool flag = false;
    if(str == name || str == ToString(type))
    {
        flag = true;
    }

    return flag;
}

