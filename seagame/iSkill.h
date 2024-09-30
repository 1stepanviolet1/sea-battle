#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include "visitor.h"
#include "field.h"

namespace seagame
{

class Field;

class iSkill : public Visitor 
{
public:
    inline void use(Field &_fd)
    { return (*this)(&_fd); }
};

} // seagame


#endif // _iSKILL_H

