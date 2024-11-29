#include "field_size_loader.h"


namespace seagame
{

void 
_GET_LOADER_NAME(FieldSize)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_m") ||
        !_json.contains("_n"))
    {
        std::invalid_argument("Invalid json for field size");
    }

    this->_obj = std::make_shared<Field::Size>(
        _json["_m"],
        _json["_n"]
    );

}

} // seagame

