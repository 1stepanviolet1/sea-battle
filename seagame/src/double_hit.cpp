#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit(const Unit &_unit)
    : _unit(_unit)
{    }

DoubleHit::DoubleHit(std::uint64_t _x, std::uint64_t _y)
    : DoubleHit(Unit(_x, _y))
{    }


void 
DoubleHit::operator()(void *_obj) 
{
    Field &_fd = *static_cast<Field*>(_obj);
    
    _fd.shot(this->_unit);

    try { _fd.shot(this->_unit); }
    catch (...) {    }
}

} // seagame

