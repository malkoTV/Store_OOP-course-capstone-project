#include <iostream>
#include <fstream>
#include "Date.h"
#include "Item.h"
#include "Seller.h"
#include "Order.h"
#include "DayBalance.h"
#include "WeekBalance.h"
#include "Listings.h"
#include "ItemType.h"

#include "Exceptions/IndexingException.h"
#include "Exceptions/LargeIdxException.h"
#include "Exceptions/NegIdxException.h"

#define N 10

using namespace std;

void Create(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);
void ShowTable(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);
void ReadFile(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);
void WriteFile(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);
void Search(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);

template<class T> void WriteTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");
template<class T> void ReadTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");

template<class T> void WriteBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");
template<class T> void ReadBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");

int main() {

    int size = 21;
    Listings listings = Listings(size);
    listings[0] = Item("White Bread", individually, 12.56);
    listings[1] = Item("Dark Bread", individually, 12.56);
    listings[2] = Item("Milk 1L", individually, 30.9);
    listings[3] = Item("Milk 2L", individually, 30.9);
    listings[4] = Item("Butter 67%", byWeight, 200.0);
    listings[5] = Item("Butter 75%", byWeight, 250.0);
    listings[6] = Item("Butter 82%", byWeight, 300.0);
    listings[7] = Item("Rice", byWeight, 30);
    listings[8] = Item("Buckwheat", byWeight, 35);
    listings[9] = Item("Oats", byWeight, 20.0);
    listings[10] = Item("Bulgur", byWeight, 23.5);
    listings[11] = Item("Chicken", byWeight, 100.0);
    listings[12] = Item("Pork", byWeight, 130.0);
    listings[13] = Item("Fish", byWeight, 110.0);
    listings[14] = Item("Sausage", byWeight, 110.0);
    listings[15] = Item("Dark Chocolate", individually, 25.0);
    listings[16] = Item("Milk Chocolate", individually, 27.0);
    listings[17] = Item("White Chocolate", individually, 29.0);
    listings[18] = Item("Apple Juice", individually, 29.0);
    listings[19] = Item("Orange Juice", individually, 29.0);
    listings[20] = Item("Cheese", byWeight, 250.0);

    //Sellers
    int sSize = 4;
    Seller* seller = new Seller[sSize];
    seller[0] = Seller("Tanya", "Gryt");
    seller[1] = Seller("Natalia", "Kuznetsova");
    seller[2] = Seller("Daria", "Hrebeniuk");
    seller[3] = Seller("Maria", "Volkova");

    Order* order = new Order[size];
    int startDay = 7;

    for(int i = 0, j = 0; i < size; i++, j++)
    {
        if(j == sSize)
        {
            j = 0;
        }

        if(listings[i].getType() == individually)
        {
            order[i] = Order(Date(startDay++, 12), seller[j], listings[i], (float)(rand() % 8 + 1));
        }
        else
        {
            order[i] = Order(Date(startDay++, 12), seller[j], listings[i], (float)((rand() % 2 + 1) + 0.001 * (rand() % 1000 + 100)));
        }

    }

    WeekBalance weekBalance = WeekBalance();

    int step = 2;

    try{
        for(int i = 0; i < W; i++)
        {
            weekBalance[i] = DayBalance(&order[i], step);
        }
    } catch (IndexingException &ex){
        ex.PrintMessage();
    }

    DayBalance* dayBalances = new DayBalance[N];
    for(int i = 0; i < N; i++)
    {
        dayBalances[i] = DayBalance(&order[i * step], step);
    }


    Order order1 = Order(Date(13, 12), seller[0], listings[0]);

    try{
        order1.setDate(*weekBalance[2].getOrders()[0].getDate());
        weekBalance[2].AddOrder(order1);

        order1.setDate(*weekBalance[5].getOrders()[0].getDate());
        order1.setSeller(seller[1]);
        weekBalance[5].AddOrder(order1);
    } catch (IndexingException &ex)
    {
        ex.PrintMessage();
    }



    while(true)
    {
        cout << "Menu" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Create new Object" << endl;
        cout << "2 - Show table for..." << endl;
        cout << "3 - Read Object from file" << endl;
        cout << "4 - Write Object to file" << endl;
        cout << "5 - Search in..." << endl;
        cout << "6 - Shop stats" << endl;

        char t;
        cin >> t;

        switch (t) {
            case '0':
                return 0;
            case '1':
                Create(&listings, &weekBalance, dayBalances);
                break;
            case '2':
                ShowTable(&listings, &weekBalance, dayBalances);
                break;
            case '3':
                ReadFile(&listings, &weekBalance, dayBalances);
                break;
            case '4':
                WriteFile(&listings, &weekBalance, dayBalances);
                break;
            case '5':
                Search(&listings, &weekBalance, dayBalances);
                break;
            case '6':
                cout << "Average order count per day:\t";
                cout << weekBalance.AvgOrderCount() << endl;
                cout << "Average order sum per day:\t";
                cout << weekBalance.AvgOrderSum() << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
        system("pause");
    }

    return 0;
}

void Create(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances)
{
    char o, t;

    cout << "Where do you want to store your object?" << endl;
    cout << "0 - quit creating\n"
         << "1 - Add Item to listings\n"
         << "2 - Add Order to DayBalance in Week balance\n"
         << "3 - Add Order to DayBalance in array\n";

    cin >> o;

    string str = "";
    string str1 = "";
    ItemType itemType = byWeight;
    float fValue = 0.0;
    char ch;
    int size = 1;

    Item* item = new Item[size];
    Order* order;
    Seller* seller;

    switch(o)
    {
        case '0':
            return;
        case '1':
            cout << "Enter the name" << endl;
            cin >> str;
            cout << "Enter the type: i - sold individually, b - by weight" << endl;
            cin >> ch;
            if(ch == 'i')
            {
                itemType = individually;
            }
            cout << "Enter the price" << endl;
            cin >> fValue;
            item = new Item(str, itemType, fValue);
            listings->AddItem(*item);
            break;
        case '2':
            try{
                cout << "To which day do you want to add order? from 0 to 6" << endl;
                int idx = -1;
                cin >> idx;

                cout << "Enter the name of an Item" << endl;
                cin >> str;
                size = 1;
                listings->Search(str, item, size);
                if(size == 0)
                {
                    cout << "Item not found" << endl;
                    return;
                }

                cout << "Enter the first name" << endl;
                cin >> str;
                cout << "Enter the last name" << endl;
                cin >> str1;
                seller = new Seller(str1, str);

                cout << "Enter the amount" << endl;
                cin >> fValue;

                order = new Order(Date(14, 12), *seller, *item, fValue);
                weekBalance->operator[](idx).AddOrder(*order);
            }
            catch(NegIdxException &ex)
            {
                ex.PrintMessage();
            }
            catch(LargeIdxException &ex)
            {
                ex.PrintMessage();
            }
            break;
        case '3':
            try{
                cout << "To which day do you want to add order? from 0 to 10" << endl;
                int idx = -1;
                cin >> idx;

                cout << "Enter the name of an Item" << endl;
                cin >> str;
                size = 1;
                listings->Search(str, item, size);
                if(size == 0)
                {
                    cout << "Item not found" << endl;
                    return;
                }

                cout << "Enter the first name of the seller" << endl;
                cin >> str;
                cout << "Enter the last name of the seller" << endl;
                cin >> str1;
                seller = new Seller(str, str1);

                cout << "Enter the amount" << endl;
                cin >> fValue;

                order = new Order(Date(14, 12), *seller, *item, fValue);
                dayBalances[idx].AddOrder(*order);
            }
            catch(IndexingException &ex)
            {
                ex.PrintMessage();
            }
            catch(SizeException &ex)
            {
                ex.PrintMessage();
            }
            break;
        default:
            cout << "Invalid input" << endl;
    }
}

void ShowTable(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances)
{
    char o;
    int idx;

    cout << "What do you want to show?\n";
    cout << "0 - quit show\n"
         << "1 - all items in the shop\n"
         << "2 - week balance\n"
         << "3 - day balance (from week balance)\n"
         << "4 - day balance (from array)\n";
    cin >> o;
    Showable* spointer;
    switch(o){
        case '0':
            return;
        case '1':
            spointer = listings;
            break;
        case '2':
            spointer = weekBalance;
            break;
        case '3':
            cout << "Enter index" << endl;
            cin >> idx;
            try{
                if(idx >= W)
                {
                    throw LargeIdxException(idx);
                }
                else if(idx < 0)
                {
                    throw NegIdxException(idx);
                }
                spointer = &(weekBalance->getDays()[idx]);

            } catch (IndexingException &ex) {
                ex.PrintMessage();
            }
            break;
        case '4':
            cout << "Enter index" << endl;
            cin >> idx;
            try{
                if(idx >= N)
                {
                    throw LargeIdxException(idx);
                }
                else if(idx < 0)
                {
                    throw NegIdxException(idx);
                }

                spointer = &dayBalances[idx];

            } catch (IndexingException &ex) {
                ex.PrintMessage();
            }
            break;
        default:
            cout << "Unknown command" << endl;
            break;
    }
    spointer->Table();
}

void ReadFile(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances)
{
    char o, f;
    cout << "What file do you want to read?" << endl;
    cout << "0 - Text\n1 - Binary\n";
    cin >> f;

    cout << "What do you want to read from file?" << endl;
    cout << "0 - quit writing to file\n"
         << "1 - Listings\n"
         << "2 - Week balance\n"
         << "3 - Day balance\n";
    cin >> o;
    if(f == '0')
    {
        switch(o)
        {
            case '0':
                return;
            case '1':
                ReadTextFile(listings, listings->operator int());
                break;
            case '2':
                ReadTextFile(weekBalance, W);
                break;
            case '3':
                ReadTextFile(dayBalances, N);
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }
    else if(f == '1')
    {
        switch(o)
        {
            case '0':
                return;
            case '1':
                ReadBinaryFile(listings, listings->operator int());
                break;
            case '2':
                ReadBinaryFile(weekBalance, W);
                break;
            case '3':
                ReadBinaryFile(dayBalances, N);
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}

void WriteFile(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances)
{
    char o, f;
    cout << "What file do you want to write?" << endl;
    cout << "0 - Text\n1 - Binary\n";
    cin >> f;

    cout << "What do you want to write to file?" << endl;
    cout << "0 - quit writing to file\n"
         << "1 - Listings\n"
         << "2 - Week balance\n"
         << "3 - Day balance (from array)\n";
    cin >> o;
    if(f == '0')
    {
        switch(o)
        {
            case '0':
                return;
            case '1':
                WriteTextFile(listings, listings->operator int());
                break;
            case '2':
                WriteTextFile(weekBalance, W);
                break;
            case '3':
                WriteTextFile(dayBalances, N);
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }
    else if(f == '1')
    {
        switch(o)
        {
            case '0':
                return;
            case '1':
                WriteBinaryFile(listings, listings->operator int());
                break;
            case '2':
                WriteBinaryFile(weekBalance, W);
                break;
            case '3':
                WriteBinaryFile(dayBalances, N);
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}

void Search(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances)
{
    char o;
    int num;
    string str;

    char mode;
    cout << "What do you want to search?" << endl;
    cout << "N - number\tS - string" << endl;
    cin >> mode;
    cout << "Enter your search" << endl;
    if(mode == 'N')
    {
        cin >> num;
    }
    else if(mode == 'S')
    {
        cin >> str;
    }
    else
    {
        mode = 'N';
        cin >> num;
    }

    int size = 5;
    Item* itemSearch = new Item[size];
    DayBalance* daySearch = new DayBalance[size];
    Order* orderSearch = new Order[size];

    cout << "What do you want to search?\n";
    cout << "0 - quit show\n"
         << "1 - item in the shop\n"
         << "2 - day balance in the past week\n"
         << "3 - day balance (from array)\n";
    cin >> o;
    switch(o){
        case '0':
            break;
        case '1':
            if(mode == 'N')
            {
                listings->Search(num, itemSearch, size);
            }
            else
            {
                listings->Search(str, itemSearch, size);
            }
            cout << "Found " << size << " items:" << endl;
            for(int i = 0; i < size; i++)
            {
                cout << itemSearch[i] << endl;
            }
            break;
        case '2':
            if(mode == 'N')
            {
                weekBalance->Search(num, daySearch, size);
            }
            else if(mode == 'S')
            {
                weekBalance->Search(str, daySearch, size);
            }
            cout << "Found " << size << " days:" << endl;
            for(int i = 0; i < size; i++)
            {
                daySearch[i].Table();
            }
            break;
        case '3':
            for(int i = 0; i < N; i++)
            {
                if(mode == 'N')
                {
                    if(dayBalances->Search(num, orderSearch, size))
                    {
                        i = N;
                    }
                }
                else if(mode == 'S')
                {
                    if(dayBalances->Search(str, orderSearch, size))
                    {
                        i = N;
                    }
                }
            }
            cout << "Found " << size << " orders:" << endl;
            for(int i = 0; i < size; i++)
            {
                orderSearch[i].Show();
            }
            break;
        default:
            cout << "Unknown command" << endl;
            break;
    }
}

template<class T> void WriteTextFile(T* object, int size, string name, string path, string format)
{
    ofstream output;
    string filepath = path + name + format;

    output.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        output.open(filepath);
        for(int i = 0; i < size; i++)
        {
            output.write((char*)&object[i], sizeof(T));
        }
        output.close();
    }
    catch (const ifstream::failure &ex)
    {
        cout << "Error opening/writing to file" << endl;
        cout << "Path: " << filepath << endl;
    }
}

template<class T> void ReadTextFile(T* object, int size, string name, string path, string format)
{
    ifstream input;
    string filepath = path + name + format;

    input.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        input.open(filepath);
        for(int i = 0; i < size; i++)
        {
            input.read((char*)&object[i], sizeof(T));
        }

        input.close();
    }
    catch (const ifstream::failure &ex)
    {
        cout << "Error opening/reading from file" << endl;
        cout << "Path: " << filepath << endl;
        ex.what();
    }
}

template<class T> void WriteBinaryFile(T* object, int size, string name, string path, string format)
{
    ofstream output;
    string filepath = path + name + format;

    output.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        output.open(filepath,ios::out | ios::binary | ios::app);
        for(int i = 0; i < size; i++)
        {
            output.write((char*)&object[i], sizeof(T));
        }
        output.close();
    }
    catch (const ifstream::failure &ex)
    {
        cout << "Error opening/writing to file" << endl;
        cout << "Path: " << filepath << endl;
    }
}

template<class T> void ReadBinaryFile(T* object, int size, string name, string path, string format)
{
    ifstream input;
    string filepath = path + name + format;

    input.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        input.open(filepath, ios::in | ios::binary);

        for(int i = 0; i < size; i++)
        {
            input.read((char*)&object[i], sizeof(T));
        }
        input.close();
    }
    catch (const ifstream::failure &ex)
    {
        cout << "Error opening/reading from file" << endl;
        cout << "Path: " << filepath << endl;
    }
}

