//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_LISTINGS_H
#define STORE_LISTINGS_H

#include <list>
#include "Item.h"

class Listings
{
private:
    std::list<Item> items;
public:
    Listings();

    //getters & setters
    std::list<Item> getItems();
    bool setItems(std::list<Item> &value);
};

#endif //STORE_LISTINGS_H
