#include "../rocket_attack_factory.h"


namespace seagame
{

std::shared_ptr<iSkill>
RocketAttackFactory::operator()(const Unit &_unit, 
                                const std::function<void(const Unit&)> _funct)
{ return std::make_shared<RocketAttack>(); }

} // seagame

