#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include <stdexcept>
#include <string>
#include <functional>

#include "visitor.h"
#include "unit.h"
#include "skill_name.h"

namespace seagame
{

class Field;
class ShipManager;

class iSkill : public Visitor 
{
public:
    enum class Name : char;

public:
    virtual inline void use(Field &_fd) = 0;

    virtual SkillName classname() const noexcept = 0;

};

} // seagame


#endif // _iSKILL_H

