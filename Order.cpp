//
// Created by 1 on 13-Nov-20.
//

#include "Order.h"

Order::Order()
{

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

Item Order::getitem()
{
    return item;
}

bool Order::setItem(Item value)
{
    item = value;
    return true;
}
