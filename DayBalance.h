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
    Order* orders;
    int size;
    float dayTotal;
public:
    DayBalance();
    DayBalance(int size);

    //getters & setters
    Order* getOrders();
    bool setOrders(Order* value);

    int getSize();

    //methods
    void Table();
};

#endif //STORE_DAYBALANCE_H
