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
    if (_m < 1 || _n < 1)
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
        this->_size = other._size;
        this->_deployed_ships = std::move(other._deployed_ships);
        this->_hit_units = std::move(other._hit_units);
        this->_unusable_units = std::move(other._unusable_units);
    }
    return *this;
}


void 
Field::add_ship(Ship &_ship, const Unit &_unit)
{
    if (this->_unusable_units.find(_unit) != this->_unusable_units.end())
        throw std::invalid_argument("bad unit for add ship");

    Ship::Len i = Ship::Len::ONE;
    while (i != _ship.len())
    {
        if (this->_unusable_units.find(Unit(
            _ship.orientation() == Ship::Orientation::HORIZONTAL 
                ? _unit.x() + i 
                : _unit.x(),
            _ship.orientation() == Ship::Orientation::VERTICAL 
                ? _unit.y() + i
                : _unit.y()
        )) != this->_unusable_units.end())
            throw std::invalid_argument("bad unit for add ship");
        
        i = Ship::Len(i + 1);
    }
    

    switch (_ship.orientation())
    {
    case Ship::Orientation::HORIZONTAL:
        if (!this->__is_valid_unit(_unit.x() + _ship.len() - 1, _unit.y()))
            throw std::invalid_argument("bad unit for add ship");
        break;

    case Ship::Orientation::VERTICAL:
        if (!this->__is_valid_unit(_unit.x(), _unit.y() + _ship.len() - 1))
            throw std::invalid_argument("bad unit for add ship");
        break;
    
    default:
        throw std::logic_error("bad orientation");
    }


    this->_deployed_ships.emplace(_unit, _ship);
    

    for (std::int8_t i = -1; i <= _ship.len(); ++i)
        this->__block_unit_for_add(Unit(
            _ship.orientation() == Ship::Orientation::HORIZONTAL
                ? _unit.x() + i
                : _unit.x(),
            _ship.orientation() == Ship::Orientation::VERTICAL
                ? _unit.y() + i
                : _unit.y()
        ), _ship.orientation());

}

void 
Field::add_ship(Ship &_ship, std::uint64_t _x, std::uint64_t _y)
{ return this->add_ship(_ship, Unit(_x, _y)); }


void 
Field::shot(const Unit &_unit)
{
    if (!this->__is_valid_unit(_unit)
      || this->_hit_units.find(_unit) != this->_hit_units.end())
        throw std::invalid_argument("bad unit for shot");

    Unit _u;
    Ship::Orientation _orie;
    std::uint8_t i;


_check_horizontal:
    _orie = Ship::Orientation::HORIZONTAL;
    for (i = 0; i < 4; ++i)
    {
        _u = Unit(
            _unit.x() - i,
            _unit.y()
        );

        if (!this->__is_valid_unit(_u))
            break;


        if (this->_deployed_ships.find(_u) != this->_deployed_ships.end())
            goto _segment_found;
    
    }
    

_check_vertical:
    _orie = Ship::Orientation::VERTICAL;
    for (i = 0; i < 4; ++i)
    {
        _u = Unit(
            _unit.x(),
            _unit.y() - i
        );
    
        if (!this->__is_valid_unit(_u))
            break;

        if (this->_deployed_ships.find(_u) != this->_deployed_ships.end())
            goto _segment_found;
    
    }

    _u = Unit();

_segment_found:
    if (std::equal_to<Unit>()(Unit(), _u)
    {
        this->_hit_units.insert(_u);
        return;
    }

    Ship &_ship = this->_deployed_ships.at(_u).get();
    
    if (_ship.len() < i)
        if (_orie == Ship::Orientation::HORIZONTAL)
            goto _check_vertical;
        else
        {
            this->_hit_units.insert(_u);
            return;
        }

    _ship.hit(i);

    _ship.segments()[i] == Ship::Integrity::DESTROYED;

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


void 
Field::__block_unit_for_add(const Unit &_unit, const Ship::Orientation &_orie)
{
    Unit _u;
    for (std::int8_t i = -1; i < 2; ++i)
    {
        _u = Unit(
            _orie == Ship::Orientation::VERTICAL
                ? _unit.x() + i
                : _unit.x(),
            _orie == Ship::Orientation::HORIZONTAL
                ? _unit.y() + i
                : _unit.y()
        );
        
        if (!this->__is_valid_unit(_u))
            continue;

        this->_unusable_units.insert(_u);
    }

}

bool 
Field::__is_valid_unit(const Unit &_u)
{
    return _u.x() > 0 && _u.x() <= this->_size.m() 
        && _u.y() > 0 && _u.y() <= this->_size.n(); 
}

bool 
Field::__is_valid_unit(std::uint64_t _x, std::uint64_t _y)
{ return this->__is_valid_unit(Unit(_x, _y)); }

} // namespace seagame

