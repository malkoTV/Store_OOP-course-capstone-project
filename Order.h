//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_ORDER_H
#define STORE_ORDER_H

#include "Date.h"
#include "Seller.h"
#include "Item.h"

class Order
{
private:
    Date date;
    Seller seller;
    Item item;
    //amount - int or float - depends on type
    float total;
public:
    Order();

    //getters & setters
    Date getDate();
    bool setDate(Date value);

    Seller getSeller();
    bool setSeller(Seller value);

    Item getitem();
    bool setItem(Item value);

    //todo amount get & set
};

#endif //STORE_ORDER_H
