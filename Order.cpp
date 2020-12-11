//
// Created by 1 on 13-Nov-20.
//

#include "Order.h"
#include "Utils.h"

Order::Order()
{
    date = Date();
    seller = Seller();
    item = Item();
    amount = 0.0;
    total = 0.0;
}

Order::Order(Date date, Seller seller, Item item, float amount)
{
    this->date = date;
    this->seller = seller;
    this->item = item;

    if(amount > 0)
    {
        this->amount = amount;
    }
    else
    {
        this->amount = 1.0;
    }

    CalculateTotal();
}

Order::Order(const Order &other)
{
    date = other.date;
    seller = other.seller;
    item = other.item;
    amount = other.amount;
    total = other.total;
}

Date* Order::getDate()
{
    return &date;
}

bool Order::setDate(Date value)
{
    date = value;
    return true;
}

Seller* Order::getSeller()
{
    return &seller;
}

bool Order::setSeller(Seller value)
{
    seller = value;
    return true;
}

Item* Order::getItem()
{
    return &item;
}

bool Order::setItem(Item value)
{
    item = value;
    CalculateTotal();
    return true;
}

float Order::getAmount()
{
    return amount;
}

bool Order::setAmount(float value)
{
    if(value > 0 && value < 10000)
    {
        amount = value;
        CalculateTotal();
        return true;
    }
    else
    {
        amount = 0;
        total = 0;
        return false;
    }
}

float Order::getTotal()
{
    return total;
}

bool Order::operator==(const Order &other) const
{
    return (date == other.date) && (seller == other.seller)
    && (item == other.item) && (total == other.total) && (amount == other.amount);
}

bool Order::operator!=(const Order &other) const
{
    return (date != other.date) || (seller != other.seller)
           || (item != other.item) || (total != other.total) || (amount != other.amount);
}

void Order::CalculateTotal() {
    total = (float)item * amount;
}

void Order::Show()
{
    int fieldLength = 25;
    int fieldCount = 4; // field count

    //headline
    Utils::print(218);
    Utils::line(196, fieldLength);

    for(int i = 1; i < fieldCount; i++)
    {
        Utils::print(194);
        Utils::line(196, fieldLength);
    }

    Utils::print(191);
    printf("\n");

    //header
    Utils::print(179); // vertical line
    printf("   %s", std::string("Date").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Date").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Seller").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Seller").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Item").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Item").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Sum").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Sum").length() - 1);
    Utils::print(179); // vertical line

    printf("\n");

    Utils::print(198);
    Utils::line(205, fieldLength);

    for(int i = 1; i < fieldCount; i++)
    {
        Utils::print(216);
        Utils::line(205, fieldLength);
    }

    Utils::print(181);
    printf("\n");

    Utils::print(179); // vertical line
    printf("   %s", std::string(date).c_str());
    Utils::line(255, fieldLength - 2 - std::string(date).length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string(seller).c_str());
    Utils::line(255, fieldLength - 2 - std::string(seller).length() - 1);
    Utils::print(179); // vertical line
    printf("%s", std::string(item).c_str());
    Utils::line(255, fieldLength - 1 - std::string(item).length() - 6);
    printf("X%5.3f ", amount);
    Utils::print(179); // vertical line
    Utils::line(255, fieldLength - 5);
    printf("%-5.2f", total);
    Utils::print(179); // vertical line

    printf("\n");

    //footer
    Utils::print(192);
    Utils::line(196, fieldLength);
    for(int i = 1; i < fieldCount; i++)
    {
        Utils::print(193);
        Utils::line(196, fieldLength);
    }

    Utils::print(217);

    printf("\n");
}

bool Order::Contains(std::string str)
{
    bool flag = false;

    if(seller.Contains(str))
    {
        flag = true;
    }
    else if(item.Contains(str))
    {
        flag = true;
    }
    return flag;
}
