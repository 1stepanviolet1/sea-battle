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
    RocketAttack(std::shared_ptr<_last_skill_result> _last_res);
    RocketAttack();

    void operator()(void *_obj) override;

    SkillName skillname() const noexcept override;

    ~RocketAttack() override = default;

private:
    Unit __get_random_unit_of_ship(const Field &_fd) noexcept;
    std::uint8_t __get_random_index_of_segments(const Ship &_ship) noexcept;

};

} // seagame


#endif // _ROCKET_ATTACK_H

