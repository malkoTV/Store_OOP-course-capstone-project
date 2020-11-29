#include <iostream>
#include <clocale>
#include "Item.h"

using namespace std;

void Table(Item* array, int n);

int main() {

    Item* item = new Item();
    Item* items = new Item[5];
    Table(items, 5);

    /*for(int i = 179; i < 256; i++)
    {
        cout << i << " - ";
        printf("%c\n", i);
    } */

    bool temp = false;
    while(temp)
    {

    }
    return 0;
}



void Table(Item* array, int n)
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
    printf("   %s", string("Name").c_str());
    line(255, fieldLength - 2 - string("Name").length() - 1);
    print(179); // vertical line
    printf("   %s", string("Type").c_str());
    line(255, fieldLength - 2 - string("Type").length() - 1);
    print(179); // vertical line
    printf("   %s", string("Price").c_str());
    line(255, fieldLength - 2 - string("Price").length() - 1);
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

    for(int i = 0; i < n; i++)
    {
        print(179); // vertical line
        printf("   %s", array[i].getName().c_str());
        line(255, fieldLength - 2 - array[i].getName().length() - 1);
        print(179); // vertical line
        printf("   %s", ToString(array[i].getType()).c_str());
        line(255, fieldLength - 2 - string(ToString(array[i].getType())).length() - 1);
        print(179); // vertical line
        printf("   %5f", array[i].getPrice());
        line(255, fieldLength - 2 - 8 - 1);
        print(179); // vertical line

        printf("\n");

        if(i < n - 1)
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
