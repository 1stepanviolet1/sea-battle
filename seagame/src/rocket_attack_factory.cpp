#include "../rocket_attack_factory.h"


namespace seagame
{

RocketAttackFactory::RocketAttackFactory(std::shared_ptr<_last_skill_result> _last_res)
    : SkillFactory(_last_res)
{    }

std::shared_ptr<iSkill>
RocketAttackFactory::create(const Unit &_unit)
{ return std::make_shared<RocketAttack>(_last_res); }


SkillName 
RocketAttackFactory::skillname() const noexcept
{ return SkillName::ROCKETATTACK; }

} // seagame

