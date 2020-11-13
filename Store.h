//
// Created by 1 on 13-Nov-20.
//

#ifndef STORE_STORE_H
#define STORE_STORE_H
#include <string>
#include <list>

class Date
{
private:
    int day;
    int month;
public:
    Date();

    //getters & setters
    int getDay();
    bool setDay();

    int getMonth();
    bool setMonth();
};

enum ItemType { byWeight, individually };
class Item
{
private:
    std::string name;
    ItemType type;
    float price;
public:
    Item();
};

class Listings
{
private:
    std::list<Item> list;
public:
    Listings();
};

class Seller
{
private:
    std::string lastName;
    std::string firstName;
    int age;
public:
    Seller();
};

class Order
{
private:
    Date date;
    Seller seller;
    Item item;
    //amount - int or float - depends on type
    float total;
public:
    Order;
};

class Balance
{
private:
    float total;
};

class DayBalance : public Balance
{
private:
    std::list<Order> orders;
public:
    DayBalance();
};

class WeekBalance : public Balance
{
private:
    std::list<DayBalance> days;
public:
    WeekBalance();
};

#endif //STORE_STORE_H
