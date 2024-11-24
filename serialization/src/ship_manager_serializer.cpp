#include "ship_manager_serializer.h"


namespace seagame
{

void 
_GET_SERIALIZER_NAME(ShipManager)::operator()(Void *_obj)
{
    ShipManager &ship_manager = static_cast<ShipManager&>(*_obj);

    this->_json["_container"] = nlohmann::json::array();

    for (std::size_t i = 0; i < ship_manager.amt(); ++i)
    {
        this->ship_serializer.save(&ship_manager[i]);
        this->_json["_container"].push_back(this->ship_serializer.get());
    }
    
}

} // seagame

