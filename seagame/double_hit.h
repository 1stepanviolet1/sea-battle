#pragma once


#ifndef _DOUBLE_HIT_H
#define _DOUBLE_HIT_H

#include <type_traits>

#include "unit.h"
#include "field.h"
#include "skill.h"

namespace seagame
{

class DoubleHit : public Skill
{
public:
    explicit DoubleHit(const Unit &_unit);
    DoubleHit(std::uint64_t _x, std::uint64_t _y);
    DoubleHit();

    void operator()(void *_obj) override;

    const SkillName& classname() const noexcept override;

    ~DoubleHit() override = default;

private:
    Unit _unit;

};

} // seagame


#endif // _DOUBLE_HIT_H

