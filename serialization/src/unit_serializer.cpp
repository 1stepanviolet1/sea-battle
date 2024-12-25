#include "unit_serializer.h"


namespace seagame
{

void 
_GET_SERIALIZER_NAME(Unit)::operator()(Void *_obj)
{
    Unit &unit = *static_cast<Unit*>(_obj);
    
    this->_json["_x"] = unit.x();
    this->_json["_y"] = unit.y();
    this->_json["_state"] = unit.state();
    
}

} // seagame

