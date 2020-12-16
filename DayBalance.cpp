//
// Created by 1 on 13-Nov-20.
//

#include "DayBalance.h"
#include "Utils.h"
#include "Exceptions/NegIdxException.h"
#include "Exceptions/LargeIdxException.h"
#include "Exceptions/NegSizeException.h"
#include "Exceptions/ZeroSizeException.h"

DayBalance::DayBalance() : Balance()
{
    size = 1;
    orders = new Order[size];
    total = 0.0;
}

DayBalance::DayBalance(int size) : Balance()
{
    if(size > 0)
    {
        this->size = size;
    }
    else
    {
        this->size = 1;
    }

    orders = new Order[this->size];
}

DayBalance::DayBalance(Order *value, int size) : Balance()
{
    if(size > 0)
    {
        this->size = size;
    }
    else
    {
        this->size = 1;
    }

    Utils::copy(value, orders, this->size);
    CalculateTotal();
}

DayBalance::DayBalance(const DayBalance &other) : Balance()
{
    size = other.size;
    orders = new Order[size];
    Utils::copy(other.orders, orders, size);
    total = other.total;
}

Order* DayBalance::getOrders()
{
    return orders;
}

bool DayBalance::setOrders(Order* value, int size)
{
    if(size > 0)
    {
        this->size = size;
    }
    else
    {
        this->size = 1;
    }

    Utils::copy(value, orders, this->size);
    CalculateTotal();
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

    for(int i = 0; i < size; i++)
    {
        Utils::print(179); // vertical line
        printf("   %s", std::string(*orders[i].getDate()).c_str());
        Utils::line(255, fieldLength - 2 - std::string(*orders[i].getDate()).length() - 1);
        Utils::print(179); // vertical line
        printf("   %s", std::string(*orders[i].getSeller()).c_str());
        Utils::line(255, fieldLength - 2 - std::string(*orders[i].getSeller()).length() - 1);
        Utils::print(179); // vertical line
        printf("%s", std::string(*orders[i].getItem()).c_str());
        Utils::line(255, fieldLength - 1 - std::string(*orders[i].getItem()).length() - 6);
        printf("X%5.3f ", orders[i].getAmount());
        Utils::print(179); // vertical line
        Utils::line(255, fieldLength - 5);
        printf("%-5.2f", orders[i].getTotal());
        Utils::print(179); // vertical line

        printf("\n");

        Utils::print(195);
        Utils::line(196, fieldLength);
        for(int i = 1; i < fieldCount; i++)
        {
            Utils::print(197);
            Utils::line(196, fieldLength);
        }

        Utils::print(180);

        printf("\n");
    }


    Utils::print(179);
    for(int i = 1; i < fieldCount - 1; i++)
    {
        Utils::line(255, fieldLength);
        Utils::print(179);
    }
    printf(" %23s  ", "Total");
    Utils::print(179);
    printf("%25.2f ", total);
    Utils::print(179);
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

void DayBalance::AddOrder(Order order) {
    size++;
    Order* temp = new Order[size];
    Utils::copy(orders, temp, size - 1);
    temp[size - 1] = order;
    delete [] orders;
    orders = temp;

    CalculateTotal();
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
    if(size < 0)
    {
        throw NegSizeException();
    }

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

void DayBalance::CalculateTotal()
{
    for(int i = 0; i < size; i++)
    {
        total += orders[i].getTotal();
    }
}
