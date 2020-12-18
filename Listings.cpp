//
// Created by 1 on 13-Nov-20.
//

#include "Item.h"
#include "Listings.h"
#include "Utils.h"
#include "Exceptions/NegIdxException.h"
#include "Exceptions/LargeIdxException.h"

Listings::Listings() : Showable()
{
    size = 1;
    items = new Item[size];
}

Listings::Listings(Item *items, int size) : Showable()
{
    if(size > 0)
    {
        this->size = size;
    }
    else
    {
        this->size = 1;
    }

    this->items = new Item[size];
    Utils::copy(items, this->items, this->size);
}

Listings::Listings(int size) : Showable()
{
    this->size = size;
    items = new Item[size];
}

Listings::Listings(const Listings &other) : Showable()
{
    size = other.size;
    Utils::copy(other.items, items, this->size);
}

Listings::~Listings()
{
    delete [] items;
}

Item* Listings::getItems()
{
    return items;
}

bool Listings::setItems(Item *value, int size)
{
    if(size > 0)
    {
        this->size = size;
    }
    else
    {
        size = 1;
    }

    Utils::copy(value, items, size);
    return true;
}

Item &Listings::operator[](int index)
{
    if(index >= 0 && index < size)
    {
        return items[index];
    }
    if(index < 0)
    {
        throw NegIdxException(index);
    }
    else if(index >= size)
    {
        throw LargeIdxException(index);
    }
    else
    {
        return items[index];
    }
}

void Listings::Table()
{
    int fieldLength = 20;

    //headline
    Utils::print(218);
    Utils::line(196, fieldLength);
    Utils::print(194);
    Utils::line(196, fieldLength);
    Utils::print(194);
    Utils::line(196, fieldLength);
    Utils::print(191);
    printf("\n");

    //header
    Utils::print(179); // vertical line
    printf("   %s", std::string("Name").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Name").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Type").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Type").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Price").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Price").length() - 1);
    Utils::print(179); // vertical line

    printf("\n");

    Utils::print(198);
    Utils::line(205, fieldLength);
    Utils::print(216);
    Utils::line(205, fieldLength);
    Utils::print(216);
    Utils::line(205, fieldLength);
    Utils::print(181);
    printf("\n");

    for(int i = 0; i < size; i++)
    {
        Utils::print(179); // vertical line
        printf("   %s", items[i].getName().c_str());
        Utils::line(255, fieldLength - 2 - items[i].getName().length() - 1);
        Utils::print(179); // vertical line
        printf("   %s", ToString(items[i].getType()).c_str());
        Utils::line(255, fieldLength - 2 - std::string(ToString(items[i].getType())).length() - 1);
        Utils::print(179); // vertical line
        printf("   %7.3f", items[i].getPrice());
        Utils::line(255, fieldLength - 10);
        Utils::print(179); // vertical line

        printf("\n");

        if(i < size - 1)
        {
            Utils::print(195);
            Utils::line(196, fieldLength);
            Utils::print(197);
            Utils::line(196, fieldLength);
            Utils::print(197);
            Utils::line(196, fieldLength);
            Utils::print(180);
        }
        else
        {
            Utils::print(192);
            Utils::line(196, fieldLength);
            Utils::print(193);
            Utils::line(196, fieldLength);
            Utils::print(193);
            Utils::line(196, fieldLength);
            Utils::print(217);
        }

        printf("\n");
    }
}

void Listings::AddItem(Item& item)
{
    size++;
    Item* temp = items;
    items = new Item[size];
    for(int i = 0; i < size - 1; i++)
    {
        items[i] = temp[i];
    }

    items[size - 1] = item;
}

Listings::operator int() const
{
    return size;
}

bool Listings::Search(std::string str, Item *item, int &s)
{
    //todo use exception handling
    bool flag = false;
    int iter = 0;

    for(int i = 0; i < size && iter < size; i++)
    {
        if(items[i].Contains(str))
        {
            flag = true;
            item[iter] = items[i];
            iter++;
        }
    }

    size = iter;
    return flag;
}

