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
    float amount;
    float total;
public:
    Order();

    //getters & setters
    Date getDate();
    bool setDate(Date value);

    Seller getSeller();
    bool setSeller(Seller value);

    Item getItem();
    bool setItem(Item value);

    float getAmount();
    bool setAmount(float value);

    float getTotal();
    bool setTotal(float value);

    //methods
    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Contains(T var)
    {
        bool flag = false;

        //to avoid checking further
        if(var == amount || var == total)
        {
            flag = true;
        }
        else if(item.Contains(var))
        {
            flag = true;
        }
        else if(date.Contains(var))
        {
            flag = true;
        }

        return flag;
    }

    bool Contains(std::string str);
};

#endif //STORE_ORDER_H
