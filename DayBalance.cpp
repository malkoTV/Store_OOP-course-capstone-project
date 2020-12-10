//
// Created by 1 on 13-Nov-20.
//

#include "DayBalance.h"
#include "ShowUtils.h"
#include "Exceptions/NegIdxException.h"
#include "Exceptions/LargeIdxException.h"

DayBalance::DayBalance() : Balance()
{
    size = 1;
    orders = new Order[size];
    total = 0.0;
}

DayBalance::DayBalance(int size) : Balance()
{
    this->size = size;
    orders = new Order[size];
}

Order* DayBalance::getOrders()
{
    return orders;
}

bool DayBalance::setOrders(Order* value)
{
    orders = value;
    return true;
}

int DayBalance::getSize() {
    return size;
}

Order& DayBalance::operator[](int index)
{
    if(index < 0)
    {
        throw NegIdxException(index);
    }
    else if(index >= size)
    {
        throw LargeIdxException(index);
    }
    else
    {
        return orders[index];
    }
}

DayBalance::operator int() const {
    return size;
}

DayBalance::operator float() const {
    return total;
}

void DayBalance::Table()
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

    for(int i = 0; i < size; i++)
    {
        ShowUtils::print(179); // vertical line
        printf("   %s", std::string(*orders[i].getDate()).c_str());
        ShowUtils::line(255, fieldLength - 2 - std::string(*orders[i].getDate()).length() - 1);
        ShowUtils::print(179); // vertical line
        printf("   %s", std::string(*orders[i].getSeller()).c_str());
        ShowUtils::line(255, fieldLength - 2 - std::string(*orders[i].getSeller()).length() - 1);
        ShowUtils::print(179); // vertical line
        printf("%s", std::string(*orders[i].getItem()).c_str());
        ShowUtils::line(255, fieldLength - 1 - std::string(*orders[i].getItem()).length() - 6);
        printf("X%5.3f ", orders[i].getAmount());
        ShowUtils::print(179); // vertical line
        ShowUtils::line(255, fieldLength - 5);
        printf("%-5.2f", orders[i].getTotal());
        ShowUtils::print(179); // vertical line

        printf("\n");

        ShowUtils::print(195);
        ShowUtils::line(196, fieldLength);
        for(int i = 1; i < fieldCount; i++)
        {
            ShowUtils::print(197);
            ShowUtils::line(196, fieldLength);
        }

        ShowUtils::print(180);

        printf("\n");
    }


    ShowUtils::print(179);
    for(int i = 1; i < fieldCount - 1; i++)
    {
        ShowUtils::line(255, fieldLength);
        ShowUtils::print(179);
    }
    printf(" %23s  ", "Total");
    ShowUtils::print(179);
    printf("%25.2f ", total);
    ShowUtils::print(179);
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

bool DayBalance::Contains(std::string str)
{
    bool flag = false;
    for(int i = 0; i < size; i++)
    {
        if(orders[i].Contains(str))
        {
            flag = true;
            i = size;
        }
    }

    return flag;
}

bool DayBalance::Search(std::string str, Order *order, int &size)
{
    //todo use exception handling
    bool flag = false;
    int iter = 0;

    for(int i = 0; i < this->size && iter < size; i++)
    {
        if(orders[i].Contains(str))
        {
            flag = true;
            order[iter] = orders[i];
            iter++;
        }
    }

    size = iter;
    return flag;
}

