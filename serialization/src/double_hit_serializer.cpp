#include "double_hit_serializer.h"


namespace seagame
{

void 
DoubleHitSerializer::operator()(Void *_obj)
{
    DoubleHit &double_hit = static_cast<DoubleHit&>(*_obj);
    
    UnitSerializer unit_serializer;
    Unit unit = double_hit.unit();
    unit_serializer.save(&unit);
    this->_json["_unit"] = unit_serializer.get();

}

} // seagame

