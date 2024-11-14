#pragma once


#ifndef _ROCKET_ATTACK_FACTORY_H
#define _ROCKET_ATTACK_FACTORY_H

#include <memory>

#include "skill_factory.h"
#include "rocket_attack.h"

namespace seagame
{

class RocketAttackFactory : public SkillFactory
{
public:
    RocketAttackFactory(std::shared_ptr<_last_skill_result> _last_res);

    std::shared_ptr<iSkill> create(const Unit& _unit = Unit()) override;

    SkillName skillname() const noexcept override;

    ~RocketAttackFactory() override = default;

};

} // seagame


#endif // _ROCKET_ATTACK_FACTORY_H

