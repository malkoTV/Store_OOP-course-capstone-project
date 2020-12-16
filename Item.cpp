//
// Created by 1 on 13-Nov-20.
//

#include <string>
#include "Item.h"

#define MAX 20

//constructors
Item::Item()
{
    name = "default";
    type = individually;
    price = 0.0f;
}

Item::Item(std::string name, ItemType type, float price)
{
    if(name != "" && name.length() < MAX)
    {
        this->name = name;
    }
    else
    {
        this->name = "default";
    }

    this->type = type;

    if(price > 0.2)
    {
        this->price = price;
    }
    else
    {
        price = 0.2;
    }
}

Item::Item(const Item &other)
{
    name = other.name;
    type = other.type;
    price = other.price;
}

//getters & setters
std::string Item::getName()
{
    return name;
}

bool Item::setName(std::string value)
{
    if(value != "" && value.length() < MAX)
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
    if(value > 0.2)
    {
        price = value;
        return true;
    }
    else
    {
        price = 0.2;
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

Item::operator float() const
{
    return price;
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

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return (os << std::string(obj));
}
