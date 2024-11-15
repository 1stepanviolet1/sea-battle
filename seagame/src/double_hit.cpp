#include "../double_hit.h"


namespace seagame
{

DoubleHit::DoubleHit(std::shared_ptr<_last_skill_result> _last_res, const Unit &_unit)
    : Skill(_last_res), _unit(_unit)
{    }

DoubleHit::DoubleHit(std::shared_ptr<_last_skill_result> _last_res, std::uint64_t _x, std::uint64_t _y)
    : DoubleHit(_last_res, Unit(_x, _y))
{    }

DoubleHit::DoubleHit(const Unit& _unit)
    : DoubleHit(std::make_shared<_last_skill_result>(), _unit)
{    }

DoubleHit::DoubleHit(std::uint64_t _x, std::uint64_t _y)
    : DoubleHit(Unit(_x, _y))
{    }

DoubleHit::DoubleHit()
    : DoubleHit(Unit())
{    }


void 
DoubleHit::operator()(Void *_obj) 
{
    std::equal_to<Unit> eq;

    if (eq(this->_unit, Unit()))
        throw std::invalid_argument("Don't setup unit for DoubleHit");

    Field &_fd = *static_cast<Field*>(_obj);
    
    _fd.shot(this->_unit);

    try { _fd.shot(this->_unit); }
    catch (std::invalid_argument) {    }

    this->_last_res->set(SkillResultStatus::SUCCESS);

}


SkillName
DoubleHit::skillname() const noexcept
{ return SkillName::DOUBLEHIT; }

} // seagame

