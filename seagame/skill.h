#pragma once


#ifndef _SKILL_H
#define _SKILL_H

#include <stdexcept>
#include <string>
#include <functional>

#include "iSkill.h"
#include "unit.h"

namespace seagame
{

class Field;
class ShipManager;

class Skill : public iSkill 
{
public:
    inline void use(Field &_fd) override
    { return this->__use(&_fd); }

    void install_data() override;
    void install_data(const Unit &_unit) override;
    void install_data(std::uint64_t _x, std::uint64_t _y);

private:
    inline void __use(void *_obj)
    { return (*this)(_obj); }

    void __throw_err_for_no_override_install_data(const Unit &_unit = Unit());

};

} // seagame


#endif // _SKILL_H

