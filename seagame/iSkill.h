#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include <stdexcept>
#include <string>

#include "visitor.h"
#include "unit.h"

namespace seagame
{

class Field;
class ShipManager;

class iSkill : public Visitor 
{
public:
    inline void use(Field &_fd)
    { return this->__use(&_fd); }

    // TODO: install_data must accept function-reaction
    virtual void install_data();
    virtual void install_data(const Unit &_unit);
    void install_data(std::uint64_t _x, std::uint64_t _y);

    virtual const std::string& __classname__() const noexcept = 0;

private:
    inline void __use(void *_obj)
    { return (*this)(_obj); }

    void __throw_err_for_no_override_install_data(const Unit &_unit = Unit());

};

} // seagame


#endif // _iSKILL_H

