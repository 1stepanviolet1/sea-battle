#include "../scanner.h"

#include <iostream>

namespace seagame
{

Scanner::Scanner(const Unit &_unit, const std::function<void(const Unit&)> &_funct)
    : _unit(_unit), _reaction(_funct)
{    }

Scanner::Scanner(std::uint64_t _x, std::uint64_t _y, const std::function<void(const Unit&)> &_funct)
    : Scanner(Unit(_x, _y), _funct)
{    }

Scanner::Scanner()
    : Scanner(Unit(), [](auto){})
{    }


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
            this->_reaction(_i_unit);
            return;
        }

    }

    this->_reaction(Unit());

}


SkillName
Scanner::classname() const noexcept
{ return SkillName::SCANNER; }

} // seagame

