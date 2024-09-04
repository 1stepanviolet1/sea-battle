#include "../ship.h"


namespace seagame
{

enum Ship::Orientation
{
    HORIZONTAL,
    VERTICAL
};

enum Ship::Integrity
{
    WHOLE,
    HALF_DESTROYED,
    DESTROYED
};

Ship::Ship(std::uint8_t len, Orientation orie)
{
    this->_len = len;
    this->_orientation = orie;

    for (std::uint8_t i = 0; i < _len; ++i)
        this->_segments.push_back(Integrity::WHOLE);
    
}

Ship::Ship(const Ship &other) noexcept 
: _len(other.len()), _orientation(other.orientation()), _segments(other.segments())
{    }

Ship::Ship(Ship &&other) noexcept 
: _len(other.len()), _orientation(other.orientation()), _segments(std::move(other._segments))
{    }

Ship& 
Ship::operator=(const Ship &other)
{
    if (this != &other)
    {
        this->_len = other.len();
        this->_orientation = other.orientation();
        this->_segments = other.segments();
    }
    return *this;
}

Ship& 
Ship::operator=(Ship &&other)
{
    if (this != &other)
    {
        this->_len = other.len();
        this->_orientation = other.orientation();
        this->_segments = std::move(other.segments());
    }
    return *this;
}

void 
Ship::hit(std::uint8_t _i)
{
    if (_i >= this->_len)
        throw std::exception("bad segment");
    
    switch (this->_segments[_i])
    {
    case Integrity::WHOLE:
        this->_segments[_i] = Integrity::HALF_DESTROYED;
        break;
    
    case Integrity::HALF_DESTROYED:
        this->_segments[_i] = Integrity::DESTROYED;
        break;
    
    case Integrity::DESTROYED:
        throw std::exception("bad hit");
    
    default:
        throw std::exception("bad Ship::Integrity");
    }
}

std::uint8_t 
Ship::len() const noexcept
{ return this->_len; }

const Ship::Orientation& 
Ship::orientation() const noexcept
{ return this->_orientation; }

const std::vector<Ship::Integrity>& 
Ship::segments() const noexcept
{ return this->_segments; }

}
