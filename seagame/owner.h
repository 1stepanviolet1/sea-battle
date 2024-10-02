#pragma once


#ifndef _OWNER_H
#define _OWNER_H

#include "visitor.h"

namespace seagame
{

class Owner
{
public:
    template <class T, class ...Args_T>
    void accept(Args_T ..._args)
    {
        T _t(_args...);
        Visitor *_v = &_t;
        this->accept(_v);
    }

    void accept(Visitor *_v);

    virtual ~Owner() = 0;

};

} // seagame


#endif // _OWNER_H

