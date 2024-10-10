#include "../scanner.h"

#include <iostream>

namespace seagame
{

Scanner::Scanner(const Unit &_unit)
{
    this->install_data(_unit);

}

Scanner::Scanner(std::uint64_t _x, std::uint64_t _y)
    : Scanner(Unit(_x, _y))
{    }

Scanner::Scanner()
    : Scanner(Unit())
{    }

void 
Scanner::install_data(const Unit &_unit)
{
    this->_unit = _unit;

}


void 
Scanner::install_reaction(std::function<void()> _reaction)
{
    this->_reaction = _reaction;

}


void 
Scanner::operator()(void *_obj)
{
    std::equal_to<Unit> eq;

    if (eq(this->_unit, Unit()))
        throw std::invalid_argument("uninstall data");
    
    if (!static_cast<bool>(this->_reaction))
        throw std::invalid_argument("uninstall reaction");

    Field &_fd = *static_cast<Field*>(_obj);
    
    if (this->_unit.x() >= _fd.size().m()
     || this->_unit.y() >= _fd.size().n())
        throw std::invalid_argument("bad unit");

    std::uint8_t _i;
    Unit _u;
    Unit _u0;
    
    for (const auto &_i_unit : std::vector<Unit>({
        Unit(this->_unit.x(), this->_unit.y()),
        Unit(this->_unit.x() + 1, this->_unit.y()),
        Unit(this->_unit.x(), this->_unit.y() + 1),
        Unit(this->_unit.x() + 1, this->_unit.y() + 1)
    }))
    {
        _u = _fd.__get_unit_of_valid_ship(_i_unit, _i);

        if (!eq(_u, _u0))
        {
            this->_reaction();
            return;
        }
        
    }

}


const std::string&
Scanner::classname() const noexcept
{ return "SCANNER"; }

} // seagame

