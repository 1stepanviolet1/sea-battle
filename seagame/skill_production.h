#pragma once


#ifndef _SKILL_PRODUCTION_H
#define _SKILL_PRODUCTION_H

#include "iSkill_factory.h"
#include "double_hit_factory.h"
#include "rocket_attack_factory.h"
#include "scanner_factory.h"
#include "skill_name.h"
#include "_last_skill_result.h"
#include "owner.h"

namespace seagame
{

class SkillProduction : public Owner
{
public:
    explicit SkillProduction(std::shared_ptr<_last_skill_result> _last_res);
    SkillProduction();

    SkillProduction(const SkillProduction &other);
    SkillProduction(SkillProduction &&other) noexcept;

    ~SkillProduction() = default;

    SkillProduction& operator=(const SkillProduction &other);
    SkillProduction& operator=(SkillProduction &&other) noexcept;

    std::shared_ptr<iSkillFactory> get_factory(SkillName _sn) const;

    std::shared_ptr<_last_skill_result> last_result() const noexcept;

private:
    std::shared_ptr<DoubleHitFactory> _double_hit_factory;
    std::shared_ptr<RocketAttackFactory> _rocket_attack_factory;
    std::shared_ptr<ScannerFactory> _scanner_factory;
    
    std::shared_ptr<_last_skill_result> _last_res;

};

} // seagame


#endif // _SKILL_PRODUCTION_H

