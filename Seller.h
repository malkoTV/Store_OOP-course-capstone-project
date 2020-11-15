//
// Created by 1 on 15-Nov-20.
//

#ifndef STORE_SELLER_H
#define STORE_SELLER_H

#include <string>

class Seller
{
private:
    std::string lastName;
    std::string firstName;
    int age;
public:
    Seller();

    //getters & setters
    std::string getLastName();
    bool setLastName(std::string value);
};

#endif //STORE_SELLER_H
