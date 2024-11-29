#include "unit_loader.h"


namespace seagame
{

void
_GET_LOADER_NAME(Unit)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_x") ||
        !_json.contains("_y") ||
        !_json.contains("_state"))
    {
        std::invalid_argument("Invalid json for unit");
    }

    this->_obj = std::make_shared<Unit>(
        _json["_x"],
        _json["_y"],
        _json["_state"]
    );

}

} // seagame

