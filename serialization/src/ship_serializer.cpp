#include "ship_serializer.h"


namespace seagame
{

void 
ShipSerializer::operator()(Void *_obj)
{
    Ship &ship = static_cast<Ship&>(*_obj);
    this->_json["_id"] = ship.id();
    this->_json["_len"] = ship.len();
    this->_json["_orientation"] = ship.orientation();

    this->_json["_segments"] = nlohmann::json::array();
    
    for (const auto &seg : ship.segments())
        this->_json["_segments"].push_back(seg);

}

} // seagame

