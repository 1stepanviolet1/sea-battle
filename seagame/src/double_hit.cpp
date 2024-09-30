#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit(const Unit &_unit)
    : _unit(_unit)
{    }

DoubleHit::DoubleHit() 
    : DoubleHit(Unit(0, 0))
{    }

void DoubleHit::operator()(void *_obj) 
{
    Field &_fd = *static_cast<Field*>(_obj);
    
    _fd.shot(this->_unit);

    try { _fd.shot(this->_unit); }
    catch (...) {    }
}

} // seagame

