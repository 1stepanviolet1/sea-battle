#include "../rocket_attack_factory.h"


namespace seagame
{

RocketAttackFactory::RocketAttackFactory(_last_skill_result& _last_res)
    : SkillFactory(_last_res)
{    }

std::shared_ptr<iSkill>
RocketAttackFactory::create(const Unit &_unit, 
                            const std::function<void(const Unit&)> &_funct)
{ return std::make_shared<RocketAttack>(); }


SkillName 
RocketAttackFactory::skillname() const noexcept
{ return SkillName::ROCKETATTACK; }

} // seagame

