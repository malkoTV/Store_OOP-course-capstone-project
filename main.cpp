#include <iostream>
#include <clocale>
#include "Item.h"
#include "Listings.h"
#include "DayBalance.h"
#include "WeekBalance.h"

using namespace std;

void Table(Item* array, int n);

int main() {

    Listings shopItems = Listings(5);
    //shopItems.Table();

    DayBalance balance = DayBalance(5);
    balance.Table();

    WeekBalance weekBalance = WeekBalance();
    //weekBalance.Table();

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
