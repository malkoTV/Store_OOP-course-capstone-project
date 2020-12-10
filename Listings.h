//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_LISTINGS_H
#define STORE_LISTINGS_H

#include <list>
#include "Item.h"
#include "Showable.h"

class Listings : public Showable
{
private:
    Item* items;
    int size;
public:
    //constructors & Destructors
    Listings();
    Listings(Item* items, int size);
    Listings(int size);
    ~Listings();

    //getters & setters
    Item* getItems();
    bool setItems(Item *&value);

    //Operators
    Item& operator[] (int index);
    operator int() const;

    //Methods
    void Table();
    void AddItem(Item& item);

    bool Search(std::string str, Item* item, int& s);

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
    bool Search(T num, Item* item, int& s)
    {
        bool flag = false;
        int iter = 0;

        for(int i = 0;  i < size && iter < s; i++)
        {
            if(items[i].Contains(num))
            {
                flag = true;
                item[iter] = items[i];
                iter++;
            }
        }

        size = iter;
        return flag;
    }
};

#endif //STORE_LISTINGS_H
