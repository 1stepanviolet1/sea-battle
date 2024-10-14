#include "../rocket_attack_factory.h"


namespace seagame
{

std::shared_ptr<iSkill>
RocketAttackFactory::create(const Unit &_unit, 
                            const std::function<void(const Unit&)> _funct)
{ return std::make_shared<RocketAttack>(); }

} // seagame

