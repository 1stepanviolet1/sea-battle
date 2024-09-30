#include "../rocket_attack.h"


namespace seagame
{

RocketAttack::RocketAttack(ShipManager &_sm)
    : _sm(_sm)
{    }


void
RocketAttack::operator()(void *_obj)
{
    ShipManager &_sm = *static_cast<ShipManager*>(_obj);

_random_shot:
    _sm[this->__get_random_index_of_ship()].hit();
}


std::size_t
__get_random_index_of_ship() const noexcept
{ return this->rd() % this->_sm.amt(); }

std::uint8_t 
__get_random_index_of_segments(const Ship &_ship) const noexcept
{ return this->rd() % _ship.len(); }

} // seagame

