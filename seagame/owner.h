#pragma once


#ifndef _OWNER_H
#define _OWNER_H

#include <memory>

#include "visitor.h"

namespace seagame
{

class Owner
{
public:
    template <class T, class ...Args_T>
    std::shared_ptr<Visitor> 
    accept(Args_T&& ..._args)
    {
        auto ptr_t = std::make_shared<T>(_args...);
        Visitor *_v = ptr_t.get();
        (*_v)(this);
        return ptr_t;
    }

    virtual ~Owner() = 0;

};

} // seagame


#endif // _OWNER_H

