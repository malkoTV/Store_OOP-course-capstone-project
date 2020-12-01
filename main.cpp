#include <iostream>
#include <clocale>
#include <fstream>
#include "Item.h"
#include "Listings.h"
#include "DayBalance.h"
#include "WeekBalance.h"

using namespace std;

void Table(Item* array, int n);
template<class T> void WriteTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");
template<class T> void ReadTextFile(T* object, int size, string name = "New file", string path = "", string format = ".txt");

template<class T> void WriteBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");
template<class T> void ReadBinaryFile(T* object, int size, string name = "New file", string path = "", string format = ".dat");

int main() {

    Listings shopItems = Listings(5);
    //shopItems.Table();

    DayBalance balance = DayBalance(5);
    //balance.Table();

    WeekBalance weekBalance = WeekBalance();
    weekBalance.Table();

    Item item = Item();
    item.setPrice(90.0);
    WriteBinaryFile(&item, 1, "Data file");
    Item item2 = Item();
    ReadBinaryFile(&item2, 1);

    cout << "Item price " << item2.getPrice() << endl;

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

template<class T> void WriteTextFile(T* object, int size, string name, string path, string format)
{
    ofstream output;
    output.open(path + name + format, ofstream::app);

    //todo write try catch block and throw an exception
    if(output.is_open())
    {
        for(int i = 0; i < size; i++)
        {
            output.write((char*)&object[i], sizeof(T));
        }
    }
    output.close();
}

template<class T> void ReadTextFile(T* object, int size, string name, string path, string format)
{
    ifstream input;
    input.open(path + name + format);

    //todo write try catch block and throw an exception
    if(input.is_open())
    {
        for(int i = 0; i < size; i++)
        {
            input.read((char*)&object[i], sizeof(T));
        }
    }
    input.close();
}

template<class T> void WriteBinaryFile(T* object, int size, string name, string path, string format)
{
    ofstream output;
    output.open(path + name + format,ios::out | ios::binary);

    //todo write try catch block and throw an exception
    if(output.is_open())
    {
        for(int i = 0; i < size; i++)
        {
            output.write((char*)&object[i], sizeof(T));
        }
    }
    output.close();
}

template<class T> void ReadBinaryFile(T* object, int size, string name, string path, string format)
{
    ifstream input;
    input.open(path + name + format, ios::out | ios::binary | ios::app);

    //todo write try catch block and throw an exception
    if(input.is_open())
    {
        for(int i = 0; i < size; i++)
        {
            input.read((char*)&object[i], sizeof(T));
        }
    }
    input.close();
}
