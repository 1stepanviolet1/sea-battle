#include "field_loader.h"


namespace seagame
{

_GET_LOADER_NAME(Field)::_GET_LOADER_NAME(Field)(ShipManager &_ship_manager)
    : _ship_manager(&_ship_manager)
{    }

_GET_LOADER_NAME(Field)::_GET_LOADER_NAME(Field)()
    : _ship_manager(nullptr)
{    }

void 
_GET_LOADER_NAME(Field)::load(const nlohmann::json &_json)
{
    if (this->_ship_manager == nullptr)
        throw std::logic_error("please, set ship manager for field loader");
    
    if (!_json.contains("_size") ||
        !_json.contains("_deployed_ships") ||
        !_json.contains("_hit_units") ||
        !_json.contains("_unusable_units"))
    {
        throw std::invalid_argument("Invalid json for field");
    }

    std::cout << '&' << std::endl;

    this->field_size_loader.load(_json["_size"]);

    Field field(
        *static_cast<Field::Size*>(this->field_size_loader.get().get())
    );

    ShipManager &_sm = *this->_ship_manager;

    std::cout << '&' << std::endl;

    for (const auto &_item : _json["_deployed_ships"])
    {
        this->unit_loader.load(_item["coords"]);

        field.add_ship(
            const_cast<Ship&>(_sm[_item["ship_id"]]),
            *static_cast<Unit*>(this->unit_loader.get().get())
        );
    }

    std::cout << '&' << std::endl;

    for (const auto &_item : _json["_hit_units"])
    {
        this->unit_loader.load(_item);
        field._hit_units.insert(*static_cast<Unit*>(this->unit_loader.get().get()));
    }

    std::cout << '&' << std::endl;

    for (const auto &_item : _json["_unusable_units"])
    {
        this->unit_loader.load(_item);
        field._unusable_units.insert(*static_cast<Unit*>(this->unit_loader.get().get()));
    }

    std::cout << '&' << std::endl;

    this->_obj = std::make_shared<Field>(std::move(field));

}

void 
_GET_LOADER_NAME(Field)::set_ship_manager(ShipManager *_ship_manager) noexcept
{
    this->_ship_manager = _ship_manager;

}

} // seagame

