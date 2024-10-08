#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include <stdexcept>

#include "visitor.h"

namespace seagame
{

class Field;
class ShipManager;

class iSkill : public Visitor 
{
public:
    inline void use(Field &_fd)
    { return this->__use(&_fd); }
 
    template <class ...Args_T>
    virtual void install_input_data(Args_T ..._args)
    { throw std::runtime_error("Override install_input_data for implement classes"); }

private:
    inline void __use(void *_obj)
    { return (*this)(_obj); }
};

} // seagame


#endif // _iSKILL_H

