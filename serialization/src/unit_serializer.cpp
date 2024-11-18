#include "unit_serializer.h"


namespace seagame
{

void 
UnitSerializer::operator()(Void *_obj)
{
    Unit &unit = static_cast<Unit&>(*_obj);
    this->_json["x"] = unit.x();
    this->_json["y"] = unit.y();
    
}

} // seagame

