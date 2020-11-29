//
// Created by 1 on 13-Nov-20.
//

#include "Item.h"
#include "Listings.h"
#include "ShowUtils.h"

Listings::Listings()
{
    size = 1;
    items = new Item[size];
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
}

void Listings::Table()
{
    int fieldLength = 20;

    //headline
    print(218);
    line(196, fieldLength);
    print(194);
    line(196, fieldLength);
    print(194);
    line(196, fieldLength);
    print(191);
    printf("\n");

    //header
    print(179); // vertical line
    printf("   %s", std::string("Name").c_str());
    line(255, fieldLength - 2 - std::string("Name").length() - 1);
    print(179); // vertical line
    printf("   %s", std::string("Type").c_str());
    line(255, fieldLength - 2 - std::string("Type").length() - 1);
    print(179); // vertical line
    printf("   %s", std::string("Price").c_str());
    line(255, fieldLength - 2 - std::string("Price").length() - 1);
    print(179); // vertical line

    printf("\n");

    print(198);
    line(205, fieldLength);
    print(216);
    line(205, fieldLength);
    print(216);
    line(205, fieldLength);
    print(181);
    printf("\n");

    for(int i = 0; i < size; i++)
    {
        print(179); // vertical line
        printf("   %s", items[i].getName().c_str());
        line(255, fieldLength - 2 - items[i].getName().length() - 1);
        print(179); // vertical line
        printf("   %s", ToString(items[i].getType()).c_str());
        line(255, fieldLength - 2 - std::string(ToString(items[i].getType())).length() - 1);
        print(179); // vertical line
        printf("   %5f", items[i].getPrice());
        line(255, fieldLength - 2 - 8 - 1);
        print(179); // vertical line

        printf("\n");

        if(i < size - 1)
        {
            print(195);
            line(196, fieldLength);
            print(197);
            line(196, fieldLength);
            print(197);
            line(196, fieldLength);
            print(180);
        }
        else
        {
            print(192);
            line(196, fieldLength);
            print(193);
            line(196, fieldLength);
            print(193);
            line(196, fieldLength);
            print(217);
        }

        printf("\n");
    }
}
