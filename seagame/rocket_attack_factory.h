#pragma once


#ifndef _ROCKET_ATTACK_FACTORY_H
#define _ROCKET_ATTACK_FACTORY_H

#include <memory>

#include "iSkill_factory.h"
#include "rocket_attack.h"

namespace seagame
{

class RocketAttackFactory : public iSkillFactory
{
public:
    std::shared_ptr<iSkill> create(const Unit &_unit = Unit(), 
                                   const std::function<void(const Unit&)> &_funct = __plug_for_react()) override;

    ~RocketAttackFactory() override = default;

};

} // seagame


#endif // _ROCKET_ATTACK_FACTORY_H

