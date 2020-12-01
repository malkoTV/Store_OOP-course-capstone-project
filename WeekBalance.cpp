//
// Created by 1 on 13-Nov-20.
//

#include "WeekBalance.h"
#include "ShowUtils.h"

WeekBalance::WeekBalance() : Balance()
{
    days = new DayBalance[W];
}

WeekBalance::~WeekBalance()
{
    delete [] days;
}

DayBalance* WeekBalance::getDays()
{
    return days;
}

bool WeekBalance::setDays(DayBalance* value)
{
    days = value;
    return true;
}

void WeekBalance::Table()
{
    int fieldLength = 15;
    int fieldCount = 3; // field count

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
    printf("   %s", std::string("Day").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Day").length() - 1);
    ShowUtils::print(179); // vertical line
    printf("   %s", std::string("Orders").c_str());
    ShowUtils::line(255, fieldLength - 2 - std::string("Orders").length() - 1);
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

    for(int i = 0; i < W; i++)
    {
        ShowUtils::print(179); // vertical line
        printf("   %s", dayName[i].c_str());
        ShowUtils::line(255, fieldLength - 2 - dayName[i].length() - 1);
        ShowUtils::print(179); // vertical line
        ShowUtils::line(255, fieldLength - 5);
        printf("%-3d  ", days[i].getSize());
        //printf("X%5.3f ", orders[i].getAmount());
        ShowUtils::print(179); // vertical line
        ShowUtils::line(255, fieldLength - 5);
        printf("%-5.2f", days[i].getTotal());
        ShowUtils::print(179); // vertical line*/

        printf("\n");

        if(i < W - 1)
        {
            ShowUtils::print(195);
            ShowUtils::line(196, fieldLength);
            for(int i = 1; i < fieldCount; i++)
            {
                ShowUtils::print(197);
                ShowUtils::line(196, fieldLength);
            }

            ShowUtils::print(180);
        }
        else
        {
            ShowUtils::print(192);
            ShowUtils::line(196, fieldLength);

            for(int i = 1; i < fieldCount; i++)
            {
                ShowUtils::print(193);
                ShowUtils::line(196, fieldLength);
            }

            ShowUtils::print(217);
        }

        printf("\n");
    }
}

