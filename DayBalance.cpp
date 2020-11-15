//
// Created by 1 on 13-Nov-20.
//

#include "DayBalance.h"

DayBalance::DayBalance() : Balance()
{

}

std::list<Order> DayBalance::getOrders()
{
    return orders;
}

bool DayBalance::setOrders(std::list<Order> value)
{
    orders = value;
    return true;
}
