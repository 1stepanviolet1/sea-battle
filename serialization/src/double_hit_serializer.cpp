#include "double_hit_serializer.h"


namespace seagame
{

void 
DoubleHitSerializer::operator()(Void *_obj)
{
    DoubleHit &double_hit = static_cast<DoubleHit&>(*_obj);
    
    Unit unit = double_hit.unit();
    this->unit_serializer.save(&unit);
    this->_json["_unit"] = this->unit_serializer.get();

}

} // seagame

