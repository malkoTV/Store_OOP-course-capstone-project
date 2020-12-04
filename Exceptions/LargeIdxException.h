//
// Created by 1 on 04-Dec-20.
//

#ifndef STORE_LARGEIDXEXCEPTION_H
#define STORE_LARGEIDXEXCEPTION_H

#include "IndexingException.h"

class LargeIdxException : public IndexingException {
public:
    //constructors
    LargeIdxException();
    LargeIdxException(int idx);

    //methods
    void PrintMessage();

};


#endif //STORE_LARGEIDXEXCEPTION_H
