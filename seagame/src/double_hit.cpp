#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit(const Unit &_unit)
{
    this->install_data(_unit);

}

DoubleHit::DoubleHit(std::uint64_t _x, std::uint64_t _y)
    : DoubleHit(Unit(_x, _y))
{    }

DoubleHit::DoubleHit()
    : DoubleHit(Unit())
{    }

void 
DoubleHit::install_data(const Unit &_unit)
{
    this->_unit = _unit;

}


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


const std::string&
DoubleHit::__classname__() const noexcept
{ return "DOUBLE_HIT"; }

} // seagame

