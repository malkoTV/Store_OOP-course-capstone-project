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
    std::string aMessage;
    std::string getAMessage(); //не може бути викликаний бо індексна помилка не має виду (індекс негативний чи завеликий)

public:
    //constructors
    IndexingException();
    IndexingException(int index);

    //getters & setters
    int getIndex();

    //methods
    virtual void PrintMessage();
};


#endif //STORE_INDEXINGEXCEPTION_H
