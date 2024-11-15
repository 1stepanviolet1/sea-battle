#include "../double_hit_factory.h"


namespace seagame
{

DoubleHitFactory::DoubleHitFactory(std::shared_ptr<_last_skill_result> _last_res)
    : SkillFactory(_last_res)
{    }

DoubleHitFactory::DoubleHitFactory()
    : DoubleHitFactory(std::make_shared<_last_skill_result>())
{    }

std::shared_ptr<iSkill>
DoubleHitFactory::create(const Unit &_unit)
{ return std::make_shared<DoubleHit>(this->_last_res, _unit); }


SkillName 
DoubleHitFactory::skillname() const noexcept
{ return SkillName::DOUBLEHIT; }

} // seagame

