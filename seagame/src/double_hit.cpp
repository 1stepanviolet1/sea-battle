#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit(const Unit &_unit)
    : _unit(_unit)
{    }

DoubleHit::DoubleHit(std::uint64_t _x, std::uint64_t _y)
    : DoubleHit(Unit(_x, _y))
{    }

DoubleHit::DoubleHit()
    : DoubleHit(Unit())
{    }


void 
DoubleHit::operator()(void *_obj) 
{
    std::equal_to<Unit> eq;

    if (eq(this->_unit, Unit()))
        throw std::invalid_argument("uninstall data");

    Field &_fd = *static_cast<Field*>(_obj);
    
    _fd.shot(this->_unit);

    try { _fd.shot(this->_unit); }
    catch (...) {    }

}


const SkillName&
DoubleHit::classname() const noexcept
{ return SkillName::DOUBLEHIT; }

} // seagame

