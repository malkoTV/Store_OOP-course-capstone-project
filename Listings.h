//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_LISTINGS_H
#define STORE_LISTINGS_H

#include <list>
#include "Item.h"
#include "Showable.h"

class Listings : public Showable
{
private:
    Item* items;
    int size;
public:
    //constructors & Destructors
    Listings();
    Listings(Item* items, int size);
    Listings(int size);
    ~Listings();

    //getters & setters
    Item* getItems();
    bool setItems(Item *&value);

    //Operators
    Item& operator[] (int index);
    Listings operator+ (const Item& item);
    operator int();

    //Methods
    void Table();
    void AddItem(Item& item);
};

#endif //STORE_LISTINGS_H
