//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_BALANCE_H
#define STORE_BALANCE_H

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

#endif //STORE_BALANCE_H
