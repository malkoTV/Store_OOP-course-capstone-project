//
// Created by 1 on 13-Nov-20.
//

#include "Order.h"
#include "ShowUtils.h"

Order::Order()
{
    date = Date();
    seller = Seller();
    item = Item();
    amount = 0.0;
    total = 0.0;
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
        return true;
    }
    else
    {
        amount = 0;
        return false;
    }
}

float Order::getTotal()
{
    return total;
}

bool Order::setTotal(float value)
{
    if(value >= 0)
    {
        total = value;
        return true;
    }
    else
    {
        total = 0;
        return false;
    }
}

void Order::Show()
{
    int fieldLength = 25;
    int fieldCount = 4; // field count

    //headline
    ShowUtils::print(218);
    ShowUtils::line(196, fieldLength);

    for(int i = 1; i < fieldCount; i++)
    {
        ShowUtils::print(194);
        ShowUtils::line(196, fieldLength);
    }

    ShowUtils::print(191);
    printf("\n");

    //header
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Date").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Date").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Seller").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Seller").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Item").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Item").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Sum").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Sum").length() - 1);
    ShowUtils::print(179); // vertical line

    printf("\n");

    ShowUtils::print(198);
    ShowUtils::line(205, fieldLength);

    for(int i = 1; i < fieldCount; i++)
    {
        ShowUtils::print(216);
        ShowUtils::line(205, fieldLength);
    }

    ShowUtils::print(181);
    printf("\n");

    ShowUtils::print(179); // vertical line
    printf("   %s", std::string(date).c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string(date).length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string(seller).c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string(seller).length() - 1);
    ShowUtils::print(179); // vertical line
    printf("%s", std::string(item).c_str());
    ShowUtils::line(255, fieldLength - 1 - std::string(item).length() - 6);
    printf("X%5.3f ", amount);
    ShowUtils::print(179); // vertical line
    ShowUtils::line(255, fieldLength - 5);
    printf("%-5.2f", total);
    ShowUtils::print(179); // vertical line

    printf("\n");

    //footer
    ShowUtils::print(192);
    ShowUtils::line(196, fieldLength);
    for(int i = 1; i < fieldCount; i++)
    {
        ShowUtils::print(193);
        ShowUtils::line(196, fieldLength);
    }

    ShowUtils::print(217);

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

