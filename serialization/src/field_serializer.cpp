#include "field_serializer.h"


namespace seagame
{

void 
FieldSerializer::operator()(Void *_obj)
{
    Field &field = static_cast<Field&>(*_obj);

    FieldSizeSerializer field_size_serializer;

    field_size_serializer.save(&field._size);
    this->_json["_size"] = field_size_serializer.get();
    
    UnitSerializer unit_serializer;

    this->_json["_deployed_ships"] = nlohmann::json::array();
    nlohmann::json _json;
    Unit _unit;
    for (auto &_pair : field._deployed_ships)
    {
        _unit = _pair.first;
        unit_serializer.save(&_unit);
        _json["coords"] = unit_serializer.get();
        _json["ship_id"] = _pair.second.get().id();
        this->_json["_deployed_ships"].push_back(_json);
    }
    
    this->_json["_hit_units"] = nlohmann::json::array();
    for (Unit _unit : field._hit_units)
    {
        unit_serializer.save(&_unit);
        this->_json["_hit_units"].push_back(unit_serializer.get());
    }

    this->_json["_unusable_units"] = nlohmann::json::array();
    for (Unit _unit : field._unusable_units)
    {
        unit_serializer.save(&_unit);
        this->_json["_unusable_units"].push_back(unit_serializer.get());
    }

}

} // seagame

