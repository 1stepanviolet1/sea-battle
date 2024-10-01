#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include "visitor.h"
#include "ship_manager.h"

namespace seagame
{

class Field;

class iSkill : public Visitor 
{
public:
    inline void use(Field &_fd)
    { return this->__use(&_fd); }

    inline void use(ShipManager &_sm)
    { return this->__use(&_sm); }

private:
    inline void __use(void *_obj)
    { return (*this)(_obj); }
};

} // seagame


#endif // _iSKILL_H

