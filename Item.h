//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_ITEM_H
#define STORE_ITEM_H
#include <iostream>

enum ItemType { byWeight, individually };
inline const std::string ToString(ItemType v)
{
    switch (v)
    {
        case byWeight:   return "By weight";
        case individually:   return "Individually";
        default:      return "[Unknown]";
    }
}

class Item
{
private:
    std::string name;
    ItemType type;
    float price;
public:
    Item();
    Item(std::string name, ItemType type, float price);

    //getters & setters
    std::string getName();
    bool setName(std::string value);

    ItemType getType();
    bool setType(ItemType value);

    float getPrice();
    bool setPrice(float value);

    //operators
    std::string operator+(const std::string& str) const;
    operator std::string() const;
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;

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

#endif //STORE_ITEM_H
