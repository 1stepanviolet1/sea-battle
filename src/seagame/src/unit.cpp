#include "../unit.h"


namespace seagame
{

explicit Unit::Unit(std::uint64_t x, std::uint64_t y, State state)
    : _x(x), _y(y), _state(state)
{    }

explicit Unit::Unit(std::uint64_t x, std::uint64_t y)
    : Unit(x, y, State::UNDEFINED)
{    }


Unit::Unit(const Unit &other)
    : _x(other._x), _y(other._y), _state(other._state)
{    }

Unit::Unit(Unit &&other) noexcept
    : _x(other._x), _y(other._y), _state(other._state)
{    }


Unit& 
Unit::operator=(const Unit &other)
{
    if (this != &other)
    {
        this->_x = other.x();
        this->_y = other.y();
        this->_state = other.state();
    }
    return *this;
}

Unit& 
Unit::operator=(Unit &&other) noexcept
{
    if (this != &other)
    {
        this->_x = other._x;
        this->_y = other._y;
        this->_state = _state;
    }
    return *this;
}


std::uint64_t Unit::x() const noexcept
{ return this->_x; }

std::uint64_t Unit::y() const noexcept
{ return this->_y; }

const Unit::State& Unit::state() const noexcept
{ return this->_state; }

} // seagame
