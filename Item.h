//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_ITEM_H
#define STORE_ITEM_H
#include <iostream>
#include "ItemType.h"

class Item
{
private:
    std::string name;
    ItemType type;
    float price;
public:
    Item();
    Item(std::string name, ItemType type, float price);
    Item(const Item &other);

    //getters & setters
    std::string getName();
    bool setName(std::string value);

    ItemType getType();
    bool setType(ItemType value);

    float getPrice();
    bool setPrice(float value);

    //operators
    operator std::string() const;
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
    operator float() const;

    //methods
    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Contains(T var)
    {
        bool flag = false;

        //to avoid checking further
        if(var == price)
        {
            flag = true;
        }

        return flag;
    }

    bool Contains(std::string str);
};

std::ostream& operator<<(std::ostream& os, const Item& obj);

#endif //STORE_ITEM_H
