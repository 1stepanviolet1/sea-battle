#include "../unit.h"


namespace seagame
{

Unit::Unit(std::uint64_t _x, std::uint64_t _y, State _state)
    : _x(_x), _y(_y), _state(_state)
{    }

Unit::Unit(std::uint64_t _x, std::uint64_t _y)
    : Unit(_x, _y, State::UNDEFINED)
{    }

Unit::Unit()
    : _x(0), _y(0)
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
        this->_state = other._state;
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


namespace std
{

std::size_t 
hash<seagame::Unit>::operator()(const seagame::Unit& u) const
{
    return hash<string>()(to_string(u.x()) + to_string(u.y()));
}

bool 
equal_to<seagame::Unit>::operator()(const seagame::Unit& lhs, const seagame::Unit& rhs) const
{
    return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}

std::size_t 
hash<std::reference_wrapper<seagame::Unit>>::operator()(const std::reference_wrapper<seagame::Unit>& u) const
{
    return hash<seagame::Unit>()(u.get());
}

bool 
equal_to<std::reference_wrapper<seagame::Unit>>::operator()(const std::reference_wrapper<seagame::Unit>& lhs, const std::reference_wrapper<seagame::Unit>& rhs) const
{
    return equal_to<seagame::Unit>()(lhs.get(), rhs.get());
}

} // std

