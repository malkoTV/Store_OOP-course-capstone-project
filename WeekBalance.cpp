//
// Created by 1 on 13-Nov-20.
//

#include <algorithm>
#include "WeekBalance.h"
#include "Utils.h"
#include "Exceptions/NegIdxException.h"
#include "Exceptions/LargeIdxException.h"

WeekBalance::WeekBalance() : Balance(){ }

WeekBalance::WeekBalance(DayBalance *days) : Balance()
{
    Utils::copy(days, this->days, W);
    CalculateTotal();
}

WeekBalance::WeekBalance(const WeekBalance &other) : Balance()
{
    Utils::copy(other.days, this->days, W);
    total = other.total;
}

DayBalance* WeekBalance::getDays()
{
    return days;
}

bool WeekBalance::setDays(DayBalance* value)
{
    Utils::copy(value, days, W);
    CalculateTotal();
    return true;
}

DayBalance& WeekBalance::operator[](int index)
{
    if(index < 0)
    {
        throw NegIdxException(index);
    }
    else if(index >= W)
    {
        throw LargeIdxException(index);
    }
    else
    {
        return days[index];
    }
}
WeekBalance::operator float() const {
    return total;
}

void WeekBalance::Table()
{
    int fieldLength = 15;
    int fieldCount = 3; // field count

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
    printf("   %s", std::string("Day").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Day").length() - 1);
    Utils::print(179); // vertical line
    printf("   %s", std::string("Orders").c_str());
    Utils::line(255, fieldLength - 2 - std::string("Orders").length() - 1);
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

    for(int i = 0; i < W; i++)
    {
        Utils::print(179); // vertical line
        printf("   %s", dayName[i].c_str());
        Utils::line(255, fieldLength - 2 - dayName[i].length() - 1);
        Utils::print(179); // vertical line
        Utils::line(255, fieldLength - 5);
        printf("%-3d  ", days[i].getSize());
        //printf("X%5.3f ", orders[i].getAmount());
        Utils::print(179); // vertical line
        Utils::line(255, fieldLength - 5);
        printf("%-5.2f", days[i].getTotal());
        Utils::print(179); // vertical line*/

        printf("\n");

        if(i < W - 1)
        {
            Utils::print(195);
            Utils::line(196, fieldLength);
            for(int i = 1; i < fieldCount; i++)
            {
                Utils::print(197);
                Utils::line(196, fieldLength);
            }

            Utils::print(180);
        }
        else
        {
            Utils::print(192);
            Utils::line(196, fieldLength);

            for(int i = 1; i < fieldCount; i++)
            {
                Utils::print(193);
                Utils::line(196, fieldLength);
            }

            Utils::print(217);
        }

        printf("\n");
    }
}

template<typename T> float average(T* arr, unsigned int size)
{
    float sum = 0.0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum / (float)size);
}

float WeekBalance::AvgOrderCount()
{
    int* temp = new int[W];
    for(int i = 0; i < W; i++)
    {
        temp[i] = days[i].getSize();
    }
    float avg = average(temp, W);
    return avg;
}

float WeekBalance::AvgOrderSum()
{
    float* temp = new float[W];
    for(int i = 0; i < W; i++)
    {
        temp[i] = days[i].getTotal();
    }
    float avg = average(temp, W);
    return avg;
}

bool WeekBalance::Search(std::string str, DayBalance* dayBalance, int& size)
{
    if(size < 0)
    {
        throw NegSizeException();
    }

    bool flag = false;
    int iter = 0;

    for(int i = 0; i < W && iter < size; i++)
    {
        if(days[i].Contains(str))
        {
            flag = true;
            dayBalance[iter] = days[i];
            iter++;
        }
    }

    size = iter;
    return flag;
}

void WeekBalance::CalculateTotal()
{
    for(int i = 0; i < W; i++)
    {
        total += days[i].getTotal();
    }
}

