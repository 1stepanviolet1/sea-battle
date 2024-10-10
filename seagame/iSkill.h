#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include <stdexcept>
#include <string>
#include <functional>

#include "visitor.h"
#include "unit.h"

namespace seagame
{

class Field;
class ShipManager;

class iSkill : public Visitor 
{
public:
    virtual inline void use(Field &_fd) = 0;

    virtual void install_data() = 0;
    virtual void install_data(const Unit &_unit) = 0;

    virtual void install_reaction(std::function<void()> _reaction) = 0;

    virtual const std::string& classname() const noexcept = 0;

};

} // seagame


#endif // _iSKILL_H

