//
// Created by 1 on 13-Nov-20.
//

#include "Store.h"

Listings::Listings()
{
    items = std::list<Item>();
}

std::list<Item> Listings::getItems()
{
    return items;
}

bool Listings::setItems(std::list<Item> &value)
{
    items = value;
    return true;
}
