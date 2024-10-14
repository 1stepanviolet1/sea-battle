#pragma once


#ifndef _SKILL_PRODUCTION_H
#define _SKILL_PRODUCTION_H

#include "iSkill_factory.h"
#include "double_hit_factory.h"
#include "rocket_attack_factory.h"
#include "scanner_factory.h"
#include "skill_name.h"

namespace seagame
{

class SkillProduction
{
public:
    SkillProduction();

    SkillProduction(const SkillProduction &other);
    SkillProduction(SkillProduction &&other) noexcept;

    ~SkillProduction() = default;

    SkillProduction& operator=(const SkillProduction &other);
    SkillProduction& operator=(SkillProduction &&other) noexcept;

    

private:
    DoubleHitFactory _dh;
    RocketAttackFactory _ra;
    ScannerFactory _sc;

};

} // seagame


#endif // _SKILL_PRODUCTION_H

