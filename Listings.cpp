//
// Created by 1 on 13-Nov-20.
//

#include "Item.h"
#include "Listings.h"
#include "ShowUtils.h"
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
        items = new Item[size];

        for(int i = 0; i < size; i++)
        {
            this->items[i] = items[i];
        }
    }
    else
    {
        size = 1;
        items = new Item[size];
    }
}

Listings::Listings(int size) : Showable()
{
    this->size = size;
    items = new Item[size];
}

Listings::~Listings()
{
    delete [] items;
}

Item* Listings::getItems()
{
    return items;
}

bool Listings::setItems(Item *&value)
{
    items = value;
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
    ShowUtils::print(218);
    ShowUtils::line(196, fieldLength);
    ShowUtils::print(194);
    ShowUtils::line(196, fieldLength);
    ShowUtils::print(194);
    ShowUtils::line(196, fieldLength);
    ShowUtils::print(191);
    printf("\n");

    //header
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Name").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Name").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Type").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Type").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Price").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Price").length() - 1);
    ShowUtils::print(179); // vertical line

    printf("\n");

    ShowUtils::print(198);
    ShowUtils::line(205, fieldLength);
    ShowUtils::print(216);
    ShowUtils::line(205, fieldLength);
    ShowUtils::print(216);
    ShowUtils::line(205, fieldLength);
    ShowUtils::print(181);
    printf("\n");

    for(int i = 0; i < size; i++)
    {
        ShowUtils::print(179); // vertical line
        printf("   %s", items[i].getName().c_str());
        ShowUtils::line(255, fieldLength - 2 - items[i].getName().length() - 1);
        ShowUtils::print(179); // vertical line
        printf("   %s", ToString(items[i].getType()).c_str());
        ShowUtils::line(255, fieldLength - 2 - std::string(ToString(items[i].getType())).length() - 1);
        ShowUtils::print(179); // vertical line
        printf("   %5f", items[i].getPrice());
        ShowUtils::line(255, fieldLength - 2 - 8 - 1);
        ShowUtils::print(179); // vertical line

        printf("\n");

        if(i < size - 1)
        {
            ShowUtils::print(195);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(197);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(197);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(180);
        }
        else
        {
            ShowUtils::print(192);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(193);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(193);
            ShowUtils::line(196, fieldLength);
            ShowUtils::print(217);
        }

        printf("\n");
    }
}

