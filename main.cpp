#include <iostream>
#include <fstream>
#include "Date.h"
#include "Item.h"
#include "Seller.h"
#include "Order.h"
#include "DayBalance.h"
#include "WeekBalance.h"
#include "Listings.h"

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

    while(true)
    {
        cout << "Menu" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Create new Object" << endl;
        cout << "2 - Show table for..." << endl;
        cout << "3 - Read Object from file" << endl;
        cout << "4 - Write Object to file" << endl;
        cout << "5 - Search in..." << endl;

        char t;
        char o;
        cin >> t;

        int idx;

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
    cout << "0 - quit writing to file\n"
         << "1 - Listings\n"
         << "2 - Week balance\n"
         << "3 - Day balance (from array)\n";
    cin >> o;

    switch(o)
    {
        case '0':
            return;
        case '1':
            cout << "Do you want to input values or create default?\ni - input\td - default";
            if(t == 'i')
            {
                string str;
                ItemType itemType;
                float price;
                char type;

                cout << "Enter the name" << endl;
                cin >> str;
                cout << "Enter the type: i - sold individually, b - by weight" << endl;
                cin >> type;
                if(type == 'b')
                {
                    itemType = individually;
                }
                else
                {
                    itemType = byWeight;
                }
                cout << "Enter the price" << endl;
                cin >> price;
                Item holder = Item(str, itemType, price);

            }
            else if(t == 'd')
            {
                Item holder = Item();
                listings->AddItem(holder);
            }

            break;
        case '2':
            try{
                cout << "What day do you want to edit? from 0 to 6" << endl;
                int idx = -1;
                cin >> idx;
                cout << "Do you want to input values or create default?\ni - input\td - default";
                Order order;
                if(t == 'i')
                {
                    string str1;
                    string str2;
                    float amount = 1.0;
                    int i = -1;

                    cout << "Enter the first name" << endl;
                    cin >> str1;
                    cout << "Enter the last name" << endl;
                    cin >> str2;
                    cout << "Enter the price" << endl;
                    cin >> amount;
                    cout << "What item do you want to buy? (Enter index)" << endl;
                    cin >> i;
                    order = Order(Date(14, 12), Seller("Jane", "Smith"), listings->operator[](i), amount);
                }
                else if(t == 'd')
                {
                    order = Order();
                }
                (weekBalance->operator[](idx)).AddOrder(order);
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
                cout << "What day do you want to edit? from 0 to 6" << endl;
                int idx = -1;
                cin >> idx;
                cout << "Do you want to input values or create default?\ni - input\td - default";
                Order order;
                if(t == 'i')
                {
                    string str1;
                    string str2;
                    float amount = 1.0;
                    int i = -1;

                    cout << "Enter the first name" << endl;
                    cin >> str1;
                    cout << "Enter the last name" << endl;
                    cin >> str2;
                    cout << "Enter the price" << endl;
                    cin >> amount;
                    cout << "What item do you want to buy? (Enter index)" << endl;
                    cin >> i;
                    order = Order(Date(14, 12), Seller("Jane", "Smith"), listings->operator[](i), amount);
                }
                else if(t == 'd')
                {
                    order = Order();
                }
                dayBalances[idx].AddOrder(order);
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
         << "3 - day balance (from array)\n"
         << "4 - day balance (from week balance)\n";
    cin >> o;
    Showable* spointer;
    switch(o){
        case '0':
            break;
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
        case '4':
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

                spointer = &weekBalance[idx];

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
         << "3 - Day balance (from array)\n";
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

    int size = 3;
    Item* itemSearch = new Item[size];
    DayBalance* daySearch = new DayBalance[size];
    Order* orderSearch = new Order[size];

    cout << "Where do you want to search?\n";
    cout << "0 - quit show\n"
         << "1 - all items in the shop\n"
         << "2 - week balance\n"
         << "3 - day balance (from week balance)\n";
    cin >> o;
    switch(o){
        case '0':
            break;
        case '1':
            if(mode == 'N')
            {
                listings->Search(num, itemSearch, size);
            }
            else if(mode == 'S')
            {
                listings->Search(str, itemSearch, size);
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
            break;
        default:
            cout << "Unknown command" << endl;
            break;
    }
    cout << "Found " << size << " objects" << endl;
}

template<class T> void WriteTextFile(T* object, int size, string name, string path, string format)
{
    ofstream output;
    string filepath = path + name + format;

    output.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        output.open(filepath, ofstream::app);
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

