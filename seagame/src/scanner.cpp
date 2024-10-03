#include "../scanner.h"


namespace seagame
{

Scanner::Scanner(const Unit &_unit)
    : _unit(_unit)
{
    if (_unit.x() < 1 || _unit.y() < 1)
        throw std::invalid_argument("bad unit");

}

Scanner::Scanner(std::uint64_t _x, std::uint64_t _y)
    : Scanner(Unit(_x, _y))
{    }


void 
Scanner::operator()(void *_obj)
{
    Field &_fd = *static_cast<Field*>(_obj);
    
    if (this->_unit.x() >= _fd.size().m()
     || this->_unit.y() >= _fd.size().n())
        throw std::invalid_argument("bad unit");

    this->_result.clear();

    std::equal_to<Unit> eq;
    std::uint8_t _i;
    Unit _u;
    Unit _u0;
    
    for (const auto &_unit : std::vector<Unit>({
        Unit(this->_unit.x(), this->_unit.y()),
        Unit(this->_unit.x() + 1, this->_unit.y()),
        Unit(this->_unit.x(), this->_unit.y() + 1),
        Unit(this->_unit.x() + 1, this->_unit.y() + 1)
    }))
    {
        _u = _fd.__get_unit_of_valid_ship(_unit, _i);

        if (!eq(_u, _u0))
            this->_result.push_back(_unit);
    }

}


const std::vector<Unit>&
Scanner::result() const noexcept
{ return this->_result; }

} // seagame

