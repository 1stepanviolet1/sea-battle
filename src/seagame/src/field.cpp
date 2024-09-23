#include "../field.h"


namespace seagame
{

Field::Size::Size(std::uint64_t _m, std::uint64_t _n)
{
    { // validation args
        std::int64_t __m = static_cast<std::int64_t>(_m);
        std::int64_t __n = static_cast<std::int64_t>(_n);

        if (__m < 0 || __n < 0)
            throw std::invalid_argument("invalid size component");
    } // validation args

    this->_m = _m;
    this->_n = _n;

}


Field::Size::Size(const Size &other)
    : _m(other.m()), _n(other.n())
{    }

Field::Size::Size(Size &&other) noexcept
    : _m(other._m), _n(other._n)
{    }


Field::Size& 
Field::Size::operator=(const Size &other)
{
    if (this != &other)
    {
        this->_m = other.m();
        this->_n = other.n();
    }
    return *this;
}

Field::Size& 
Field::Size::operator=(Size &&other) noexcept
{
    if (this != &other)
    {
        this->_m = other._m;
        this->_n = other._n;
    }
    return *this;
}


std::uint64_t Field::Size::m() const noexcept
{ return this->_m; }

std::uint64_t Field::Size::n() const noexcept
{ return this->_n; }


Field::Field(std::uint64_t _m, std::uint64_t _n)
    : _size(_m, _n)
{
    if (_m < 0 || _n < 0)
        throw std::invalid_argument("minimal field size: 1x1");

}

Field::Field(Size _size)
    : _size(_size)
{    }


Field::Field(const Field &other)
    : _size(other.size()), 
      _deployed_ships(other._deployed_ships), 
      _hit_units(other._hit_units),
      _unusable_units(other._unusable_units)
{    }

Field::Field(Field &&other) noexcept
    : _size(other._size), 
      _deployed_ships(std::move(other._deployed_ships)), 
      _hit_units(std::move(other._hit_units)),
      _unusable_units(std::move(other._unusable_units))
{    }


Field&
Field::operator=(const Field &other)
{
    if (this != &other)
    {
        this->_size = other.size();
        this->_deployed_ships = other._deployed_ships;
        this->_hit_units = other._hit_units;
        this->_unusable_units = other._unusable_units;
    }
    return *this;
}

Field&
Field::operator=(Field &&other) noexcept
{
    if (this != &other)
    {
        this->_size = _size;
        this->_deployed_ships = std::move(other._deployed_ships);
        this->_hit_units = std::move(other._hit_units);
        this->_unusable_units = std::move(other._unusable_units);
    }
    return *this;
}


void 
Field::add_ship(Ship &_ship, const Unit &_unit)
{
    Ship::Len i = Ship::Len::ONE;
    do
    {
        if (this->_unusable_units.find(Unit(
            _ship.orientation() == Ship::Orientation::HORIZONTAL 
                ? _unit.x() + i - 1 
                : _unit.x(),
            _ship.orientation() == Ship::Orientation::VERTICAL 
                ? _unit.y() + i - 1
                : _unit.y()
        )) != this->_unusable_units.end())
            throw std::invalid_argument("bad unit for add ship");
        
        i = Ship::Len(i + 1);
    } while (i != _ship.len());
    

    switch (_ship.orientation())
    {
    case Ship::Orientation::HORIZONTAL:
        if (
            _unit.x() + _ship.len() > this->_size.m()
            || _unit.y() > this->_size.n()
           )
            throw std::invalid_argument("bad unit for add ship");

        break;

    case Ship::Orientation::VERTICAL:
        if (
            _unit.y() + _ship.len() > this->_size.n()
            || _unit.x() > this->_size.m()
           )
            throw std::invalid_argument("bad unit for add ship");

        break;
    
    default:
        throw std::logic_error("bad orientation");
    }


    this->_deployed_ships.emplace(_ship, _unit);

    // TODO:

}

void 
Field::add_ship(Ship &_ship, std::uint64_t _x, std::uint64_t y)
{
    // TODO:
}


void 
Field::shot(const Unit &_unit)
{
    // TODO:
}

void 
Field::shot(std::uint64_t _x, std::uint64_t _y)
{
    // TODO:
}


const Field::Size& 
Field::size() const noexcept
{ return this->_size; }

} // namespace seagame
