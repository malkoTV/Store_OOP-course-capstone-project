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
public:
    DayBalance();
    DayBalance(int size);

    //getters & setters
    Order* getOrders();
    bool setOrders(Order* value);
    int getSize();

    //operators
    Order& operator[](int index);

    //methods
    void Table();

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Contains(T var)
    {
        bool flag = false;
        for(int i = 0; i < size; i++)
        {
            if(orders[i].Contains(var))
            {
                flag = true;
                i = size;
            }
        }

        return flag;
    }

    bool Contains(std::string str);
};

#endif //STORE_DAYBALANCE_H
