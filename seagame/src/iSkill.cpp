#include "../iSkill.h"

namespace seagame 
{

void
iSkill::install_data()
{ return this->__throw_err_for_no_override_install_data(); }

void
iSkill::install_data(const Unit &_unit)
{ return this->__throw_err_for_no_override_install_data(_unit); }

void 
iSkill::install_data(std::uint64_t _x, std::uint64_t _y)
{ return this->install_data(Unit(_x, _y)); }


void 
iSkill::__throw_err_for_no_override_install_data(const Unit &_unit)
{
    std::equal_to<Unit> eq;

    if (eq(_unit, Unit()))
        throw std::runtime_error("iSkill::install_data() not overridden");
    
    throw std::runtime_error("iSkill::install_data(Unit) not overridden");

}

} // seagame
