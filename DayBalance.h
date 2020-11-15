//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_DAYBALANCE_H
#define STORE_DAYBALANCE_H

#include <list>
#include "Order.h"
#include "Balance.h"

class DayBalance : public Balance
{
private:
    std::list<Order> orders;
public:
    DayBalance();

    //getters & setters
    std::list<Order> getOrders();
    bool setOrders(std::list<Order> value);
};

#endif //STORE_DAYBALANCE_H
