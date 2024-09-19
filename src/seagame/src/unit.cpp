#include "../unit.h"


namespace seagame
{

enum Unit::State
{
    NULL,
    EMPTY,
    SHIP
};


explicit Unit::Unit(std::uint64_t x, std::uint64_t y, State state)
: _x(x), _y(y), _state(state)
{    }

explicit Unit::Unit(std::uint64_t x, std::uint64_t y)
: Unit(x, y, State::NULL)
{    }


std::uint64_t Unit::x() const noexcept
{ return this->_x; }

std::uint64_t Unit::y() const noexcept
{ return this->_y; }

const State& Unit::state() const noexcept
{ return this->_state; }

} // seagame

