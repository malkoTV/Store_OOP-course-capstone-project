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

    Item* item = new Item();
    item->setPrice(90.0);
    WriteTextFile(item, 1, "File skdhfwKEFB");
    Item* item2 = new Item();
    ReadTextFile(item2, 1, "kdjhglkh");

    cout << "Item price " << item2->getPrice() << endl;

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
