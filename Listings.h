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
    Item* items;
    int size;
public:
    Listings();

    //getters & setters
    Item* getItems();
    bool setItems(Item *&value);

    //Operators
    Item& operator[] (int index);

    //Methods
    void Table();
};

#endif //STORE_LISTINGS_H
