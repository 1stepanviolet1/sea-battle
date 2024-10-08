#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit()
    : _unit()
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

