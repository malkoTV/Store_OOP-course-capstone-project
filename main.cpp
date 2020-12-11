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

void ShowTable(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);
void Search(Listings* listings, WeekBalance* weekBalance, DayBalance* dayBalances);

template<class T> void WriteTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");
template<class T> void ReadTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");

template<class T> void WriteBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");
template<class T> void ReadBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");

int main() {

    Item item = Item();
    cout << "Item " << item << endl;

    Date date = Date();
    cout << "Date " << date << endl;


    Listings shopItems = Listings(5);
    //shopItems.Table();
    cout << "Item count " << (int)shopItems << endl;
    try{
        shopItems[10];
    }
    catch(NegIdxException ex)
    {
        ex.PrintMessage();
    }
    catch(LargeIdxException ex)
    {
        ex.PrintMessage();
    }


    DayBalance balance = DayBalance(5);
    //balance.Table();
    try{
        balance[12];
    }
    catch(NegIdxException ex)
    {
        ex.PrintMessage();
    }
    catch(LargeIdxException ex)
    {
        ex.PrintMessage();
    }

    WeekBalance weekBalance = WeekBalance();
    //weekBalance.Table();
    try{
        weekBalance[-2];
    }
    catch(NegIdxException ex)
    {
        ex.PrintMessage();
    }
    catch(LargeIdxException ex)
    {
        ex.PrintMessage();
    }


    Listings listings = Listings();
    DayBalance* dayBalances = new DayBalance[N];


    int temp = 1;
    //cout << "Enter 1 to go to menu\n";
    //cin >> temp;
    while(temp)
    {
        cout << "Menu" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Create new Object" << endl;
        cout << "2 - Show table for..." << endl;
        cout << "3 - Read Object from file" << endl;
        cout << "4 - Write Object to file" << endl;
        cout << "5 - Search in..." << endl;
        cout << "6 - Edit Object" << endl;

        char t;
        char o;
        cin >> t;

        int idx;

        switch (t) {
            case '0':
                return 0;
            case '1':
                break;
            case '2':
                ShowTable(&listings, &weekBalance, dayBalances);
                break;
            case '3':
                cout << "What do you want to read from file?" << endl;
                cout << "0 - quit show\n"
                     << "1 - Listings\n"
                     << "2 - Week balance\n"
                     << "3 - Day balance (from array)\n";
                cin >> o;
                switch(o)
                {

                }
                break;
            case '4':
                break;
            case '5':
                Search(&listings, &weekBalance, dayBalances);
                break;
            case '6':
                break;
            default:
                cout << "Invalid input" << endl;
        }
        system("pause");
    }

    return 0;
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

