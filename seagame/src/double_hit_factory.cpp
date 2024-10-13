#include "../double_hit_factory.h"


namespace seagame
{

std::shared_ptr<iSkill>
DoubleHitFactory::operator()(const Unit &_unit, 
                             const std::function<void(const Unit&)> _funct)
{ return std::make_shared<DoubleHit>(_unit); }

} // seagame

