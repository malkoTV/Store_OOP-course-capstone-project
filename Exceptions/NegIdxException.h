//
// Created by 1 on 04-Dec-20.
//

#ifndef STORE_NEGIDXEXCEPTION_H
#define STORE_NEGIDXEXCEPTION_H

#include "IndexingException.h"

class NegIdxException : public IndexingException {
public:
    //constructors
    NegIdxException();
    NegIdxException(int idx);
};


#endif //STORE_NEGIDXEXCEPTION_H
