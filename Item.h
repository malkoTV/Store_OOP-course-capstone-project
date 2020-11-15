//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_ITEM_H
#define STORE_ITEM_H
#include <iostream>

enum ItemType { byWeight, individually };
class Item
{
private:
    std::string name;
    ItemType type;
    float price;
public:
    Item();

    //getters & setters
    std::string getName();
    bool setName(std::string value);

    ItemType getType();
    bool setType(ItemType value);

    float getPrice();
    bool setPrice(float value);
};

#endif //STORE_ITEM_H
