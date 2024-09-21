#include "../field.h"


namespace seagame
{

explicit Field::Size::Size(std::uint64_t m, std::uint64_t n)
{
    { // validation args
        std::int64_t __m = static_cast<std::int64_t>(m);
        std::int64_t __n = static_cast<std::int64_t>(n);

        if (__m < 0 or __n < 0)
            throw std::std::invalid_argument("invalid size component");
    } // validation args

    this->_m = m;
    this->_n = n;

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


Field::Field(std::uint64_t m, std::uint64_t n)
    : _size(m, n)
{    }

Field::Field(Size size)
    : _size(size)
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

} // namespace seagame

