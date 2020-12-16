//
// Created by 1 on 29-Nov-20.
//

#ifndef STORE_UTILS_H
#define STORE_UTILS_H

#include <iostream>

class Utils {
public:
    //table
    static void line(char s, int n);
    static void print(char code);

    //copying
    template<class T>
    static void copy(const T* from, T* to, int s)
    {
        for(int i = 0; i < s; i++)
        {
            to[i] = from[i];
        }
    }
};

#endif //STORE_UTILS_H
