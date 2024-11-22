#include "unit_serializer.h"


namespace seagame
{

void 
UnitSerializer::operator()(Void *_obj)
{
    Unit &unit = static_cast<Unit&>(*_obj);
    
    this->_json["_x"] = unit.x();
    this->_json["_y"] = unit.y();
    this->_json["_state"] = unit.state();
    
}

} // seagame

