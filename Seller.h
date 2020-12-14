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
    //constructors
    Seller();
    Seller(std::string lastName, std::string firstName, int age = 18);
    Seller(const Seller& other);

    //getters & setters
    std::string getLastName();
    bool setLastName(std::string value);

    std::string getFirstName();
    bool setFirstName(std::string value);

    int getAge();
    bool setAge(int value);

    //operators
    operator std::string() const;
    bool operator==(const Seller &other) const;
    bool operator!=(const Seller &other) const;

    //methods
    bool Contains(std::string str);
};

std::ostream& operator<<(std::ostream& os, const Seller& obj);

#endif //STORE_SELLER_H
