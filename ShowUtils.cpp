//
// Created by 1 on 30-Nov-20.
//

#include "ShowUtils.h"

void ShowUtils::line(char s, int n)
{
    for(int i = 0; i <= n; i++)
    {
        printf("%c", s);
    }
}

void ShowUtils::print(char code)
{
    printf("%c", code);
}