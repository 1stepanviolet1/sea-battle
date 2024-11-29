#include "ship_manager_loader.h"


namespace seagame
{

void 
_GET_LOADER_NAME(ShipManager)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_container"))
    {
        std::invalid_argument("Invalid json for ship manager");
    }

    std::vector<Ship> ships;

    Ship *ship;
    for (const auto &ship_json : _json["_container"])
    {
        this->ship_loader.load(ship_json);
        ship = static_cast<Ship*>(ship_loader.get().get());
        ships.push_back(*ship);
    }

    ShipManager ship_manager(
        std::vector<Ship::Len>(ships.size())
    );

    for (const auto &ship : ships)
        ship_manager[ship.id()] = std::move(ship);

    this->_obj = std::make_shared<ShipManager>(std::move(ship_manager));

}

} // seagame

