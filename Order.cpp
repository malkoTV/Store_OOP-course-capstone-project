//
// Created by 1 on 13-Nov-20.
//

#include "Order.h"

Order::Order()
{
    date = Date();
    seller = Seller();
    item = Item();
    amount = 0.0;
    total = 0.0;
}

Date Order::getDate()
{
    return date;
}

bool Order::setDate(Date value)
{
    date = value;
    return true;
}

Seller Order::getSeller()
{
    return seller;
}

bool Order::setSeller(Seller value)
{
    seller = value;
    return true;
}

Item Order::getItem()
{
    return item;
}

bool Order::setItem(Item value)
{
    item = value;
    return true;
}

float Order::getAmount()
{
    return amount;
}

bool Order::setAmount(float value)
{
    if(value > 0 && value < 10000)
    {
        amount = value;
        return true;
    }
    else
    {
        amount = 0;
        return false;
    }
}

float Order::getTotal()
{
    return total;
}

bool Order::setTotal(float value)
{
    if(value >= 0)
    {
        total = value;
        return true;
    }
    else
    {
        total = 0;
        return false;
    }
}
