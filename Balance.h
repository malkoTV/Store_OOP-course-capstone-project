//
// Created by 1 on 15-Nov-20.
//

#include "Showable.h"

#ifndef STORE_BALANCE_H
#define STORE_BALANCE_H

class Balance : public Showable
{
protected:
    float total;
public:
    Balance();

    //getters & setters
    float getTotal();
};

#endif //STORE_BALANCE_H
