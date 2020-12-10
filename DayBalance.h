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
    operator int() const;
    operator float() const;

    //methods
    void Table();

    bool Search(std::string str, Order* order, int& size);

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Search(T num, Order* order, int& s)
    {
        bool flag = false;
        int iter = 0;

        for(int i = 0;  i < size && iter < s; i++)
        {
            if(orders[i].Contains(num))
            {
                flag = true;
                order[iter] = orders[i];
                iter++;
            }
        }

        s = iter;
        return flag;
    }

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Contains(T var)
    {
        bool flag = false;
        for(int i = 0; i < size && !flag; i++)
        {
            if(orders[i].getAmount() == var || orders[i].getTotal() == var)
            {
                flag = true;
                i = size;
            }
            else if(orders[i].Contains(var))
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
