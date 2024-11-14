#pragma once


#ifndef _DOUBLE_HIT_H
#define _DOUBLE_HIT_H

#include "unit.h"
#include "field.h"
#include "skill.h"

namespace seagame
{

class DoubleHit : public Skill
{
public:
    explicit DoubleHit(std::shared_ptr<_last_skill_result> _last_res, const Unit &_unit);
    DoubleHit(std::shared_ptr<_last_skill_result> _last_res, std::uint64_t _x, std::uint64_t _y);
    DoubleHit();

    void operator()(void *_obj) override;

    SkillName skillname() const noexcept override;

    ~DoubleHit() override = default;

private:
    Unit _unit;

};

} // seagame


#endif // _DOUBLE_HIT_H

