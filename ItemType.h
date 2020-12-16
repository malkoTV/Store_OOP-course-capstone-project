//
// Created by 1 on 16-Dec-20.
//

#ifndef STORE_ITEMTYPE_H
#define STORE_ITEMTYPE_H

#include <string>

enum ItemType { byWeight, individually };
inline const std::string ToString(ItemType v)
{
    switch (v)
    {
        case byWeight:   return "By weight";
        case individually:   return "Individually";
        default:      return "[Unknown]";
    }
}

#endif //STORE_ITEMTYPE_H
