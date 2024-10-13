#pragma once


#ifndef _ROCKET_ATTACK_H
#define _ROCKET_ATTACK_H

#include <random>

#include "unit.h"
#include "field.h"
#include "skill.h"

namespace seagame
{

class RocketAttack : public Skill
{
private:
    std::random_device rd;

public:
    RocketAttack();

    void operator()(void *_obj) override;

    const SkillName& classname() const noexcept override;

    ~RocketAttack() override = default;

private:
    Unit __get_random_unit_of_ship(const Field &_sm) noexcept;
    std::uint8_t __get_random_index_of_segments(const Ship &_ship) noexcept;

};

} // seagame


#endif // _ROCKET_ATTACK_H

