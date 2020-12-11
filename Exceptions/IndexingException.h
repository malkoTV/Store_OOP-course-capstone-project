//
// Created by 1 on 04-Dec-20.
//

#ifndef STORE_INDEXINGEXCEPTION_H
#define STORE_INDEXINGEXCEPTION_H

#include <string>
#include "ArgumentException.h"

class IndexingException : public ArgumentException {
protected:
    int index;
public:
    //constructors
    IndexingException(int index);

    //getters & setters
    int getIndex();

    //methods
    void PrintMessage();
};


#endif //STORE_INDEXINGEXCEPTION_H
