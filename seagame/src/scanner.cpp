#include "../scanner.h"


namespace seagame
{

Scanner::Scanner(std::shared_ptr<_last_skill_result> _last_res, const Unit &_unit)
    : Skill(_last_res), _unit(_unit)
{    }

Scanner::Scanner(std::shared_ptr<_last_skill_result> _last_res, std::uint64_t _x, std::uint64_t _y)
    : Scanner(_last_res, Unit(_x, _y))
{    }

Scanner::Scanner(const Unit& _unit)
    : Scanner(std::make_shared<_last_skill_result>(), _unit)
{    }

Scanner::Scanner(std::uint64_t _x, std::uint64_t _y)
    : Scanner(Unit(_x, _y))
{    }

Scanner::Scanner()
    : Scanner(Unit())
{    }


void 
Scanner::operator()(Void *_obj)
{
    std::equal_to<Unit> eq;

    if (eq(this->_unit, Unit()))
        throw std::invalid_argument("uninstall data");

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
            this->_last_res->set(SkillResultStatus::FOUND_SHIP);
            return;
        }

    }

    this->_last_res->set(SkillResultStatus::NOT_FOUND_SHIP);

}


SkillName
Scanner::skillname() const noexcept
{ return SkillName::SCANNER; }

Unit
Scanner::unit() const noexcept
{ return this->_unit; }

} // seagame

