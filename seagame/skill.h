#pragma once


#ifndef _SKILL_H
#define _SKILL_H

#include <stdexcept>
#include <string>
#include <functional>

#include "iSkill.h"
#include "unit.h"
#include "skill_name.h"

namespace seagame
{

class Field;
class ShipManager;

class Skill : public iSkill 
{
public:
    inline void use(Field &_fd) override
    { return this->__use(&_fd); }

private:
    inline void __use(void *_obj)
    { return (*this)(_obj); }

};

} // seagame


#endif // _SKILL_H

