#include "../skill.h"


namespace seagame 
{

void
Skill::install_data()
{ return this->__throw_err_for_no_override_install_data(); }

void
Skill::install_data(const Unit &_unit)
{ return this->__throw_err_for_no_override_install_data(_unit); }

void 
Skill::install_data(std::uint64_t _x, std::uint64_t _y)
{ return this->install_data(Unit(_x, _y)); }


void 
Skill::__throw_err_for_no_override_install_data(const Unit &_unit)
{
    std::equal_to<Unit> eq;

    if (eq(_unit, Unit()))
        throw std::runtime_error("Skill::install_data() not overridden");
    
    throw std::runtime_error("Skill::install_data(Unit) not overridden");

}

} // seagame
