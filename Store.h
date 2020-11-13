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
    bool setDay(int value);

    int getMonth();
    bool setMonth(int value);
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

    //getters & setters
    std::string getName();
    bool setName(std::string value);

    ItemType getType();
    bool setType(ItemType value);

    float getPrice();
    bool setPrice(float value);
};

class Listings
{
private:
    std::list<Item> items;
public:
    Listings();

    //getters & setters
    std::list<Item> getItems();
    bool setItems(std::list<Item> &value);
};

class Seller
{
private:
    std::string lastName;
    std::string firstName;
    int age;
public:
    Seller();

    //getters & setters
    std::string getLastName();
    bool setLastName(std::string value);
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
    Order();

    //getters & setters
    Date getDate();
    bool setDate(Date value);

    Seller getSeller();
    bool setSeller(Seller value);

    Item getitem();
    bool setItem(Item value);

    //todo amount get & set
};

class Balance
{
private:
    float total;
public:
    Balance();

    //getters & setters
    float getTotal();
    bool setTotal(float value);
};

class DayBalance : public Balance
{
private:
    std::list<Order> orders;
public:
    DayBalance();

    //getters & setters
    std::list<Order> getOrders();
    bool setOrders(std::list<Order> value);
};

class WeekBalance : public Balance
{
private:
    std::list<DayBalance> days;
public:
    WeekBalance();

    //getters & setters
    std::list<DayBalance> getDays();
    bool setDays(std::list<DayBalance> value);
};

#endif //STORE_STORE_H
