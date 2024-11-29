#include "field_loader.h"


namespace seagame
{

_GET_LOADER_NAME(Field)::_GET_LOADER_NAME(Field)(const ShipManager &_ship_manager)
    : _ship_manager(_ship_manager)
{    }

void 
_GET_LOADER_NAME(Field)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_size") ||
        !_json.contains("_deployed_ships") ||
        !_json.contains("_hit_units") ||
        !_json.contains("_unusable_units"))
    {
        std::invalid_argument("Invalid json for unit");
    }

    this->field_size_loader.load(_json["_size"]);

    Field field(
        *static_cast<Field::Size*>(this->field_size_loader.get().get())
    );

    for (const auto &_item : _json["_deployed_ships"])
    {
        this->unit_loader.load(_item["coords"]);

        field.add_ship(
            const_cast<Ship&>(this->_ship_manager[_item["ship_id"]]),
            *static_cast<Unit*>(this->unit_loader.get().get())
        );
    }

    for (const auto &_item : _json["_hit_units"])
    {
        this->unit_loader.load(_item);
        field._hit_units.insert(*static_cast<Unit*>(this->unit_loader.get().get()));
    }

    for (const auto &_item : _json["_unusable_units"])
    {
        this->unit_loader.load(_item);
        field._unusable_units.insert(*static_cast<Unit*>(this->unit_loader.get().get()));
    }

    this->_obj = std::make_shared<Field>(std::move(field));

}

} // seagame

