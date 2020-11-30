//
// Created by 1 on 15-Nov-20.
//

#include "Showable.h"

#ifndef STORE_BALANCE_H
#define STORE_BALANCE_H

class Balance : public Showable
{
private:
    float total;
public:
    Balance();

    //getters & setters
    float getTotal();
    bool setTotal(float value);
};

#endif //STORE_BALANCE_H
