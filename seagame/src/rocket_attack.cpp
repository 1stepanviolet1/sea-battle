#include "../rocket_attack.h"


namespace seagame
{

RocketAttack::RocketAttack()
{    }


void
RocketAttack::operator()(void *_obj)
{
    ShipManager &_sm = *static_cast<ShipManager*>(_obj);
    
    Ship _ship = _sm[
        this->__get_random_index_of_ship(_sm)
    ];

    _ship.hit(
        this->__get_random_index_of_segments(_ship)
    );

}


std::uint64_t
RocketAttack::__get_random_index_of_ship(const ShipManager &_sm) noexcept
{
    std::vector<std::uint64_t> _valid_ships_indices;

    for (const auto &_ship : _sm.container())
    {
        if (!_ship.is_destroyed())
            _valid_ships_indices.push_back(_ship.id());
    }

    return _valid_ships_indices[this->rd() % _valid_ships_indices.size()];

}

std::uint8_t 
RocketAttack::__get_random_index_of_segments(const Ship &_ship) noexcept
{
    std::vector<std::uint8_t> _valid_ship_segments;

    for (const auto &_seg : _ship.segments())
    {
        if (_seg != Ship::Integrity::DESTROYED)
            _valid_ship_segments.push_back(_seg);
    }

    return _valid_ship_segments[this->rd() % _valid_ship_segments.size()];
}

} // seagame

