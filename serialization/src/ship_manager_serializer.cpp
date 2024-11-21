#include "ship_manager_serializer.h"


namespace seagame
{

void 
ShipManagerSerializer::operator()(Void *_obj)
{
    ShipManager &ship_manager = static_cast<ShipManager&>(*_obj);

    this->_json["_container"] = nlohmann::json::array();

    ShipSerializer ship_serializer;

    for (std::size_t i = 0; i < ship_manager.amt(); ++i)
    {
        ship_serializer.save(&ship_manager[i]);
        this->_json["_container"].push_back(ship_serializer.get());
    }
    
}

} // seagame

