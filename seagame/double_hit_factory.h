#pragma once


#ifndef _DOUBLE_HIT_FACTORY_H
#define _DOUBLE_HIT_FACTORY_H

#include <memory>

#include "skill_factory.h"
#include "double_hit.h"

namespace seagame
{

class DoubleHitFactory : public SkillFactory
{
public:
    explicit DoubleHitFactory(std::shared_ptr<_last_skill_result> _last_res);
    DoubleHitFactory();

    std::shared_ptr<iSkill> create(const Unit& _unit) override;

    SkillName skillname() const noexcept override;

    ~DoubleHitFactory() override = default;

};

} // seagame


#endif // _DOUBLE_HIT_FACTORY_H

