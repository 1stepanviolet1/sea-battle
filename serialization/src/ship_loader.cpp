#include "ship_loader.h"


namespace seagame
{

void
_GET_LOADER_NAME(Ship)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_id") ||
        !_json.contains("_len") ||
        !_json.contains("_orientation") ||
        !_json.contains("_segments"))
    {
        throw std::invalid_argument("Invalid json for ship");
    }

    std::vector<Ship::Integrity> _segments = _json["_segments"];

    Ship ship = Ship(
        static_cast<Ship::Len>(_json["_len"]),
        static_cast<Ship::Orientation>(_json["_orientation"])
    );
    ship._id = static_cast<std::uint64_t>(_json["_id"]);

    for (std::size_t i = 0; i < _segments.size(); ++i)
    {
        while (_segments[i] != ship.segments()[i])
            ship.hit(i);
    }

    this->_obj = std::make_shared<Ship>(std::move(ship));

}

} // seagame

