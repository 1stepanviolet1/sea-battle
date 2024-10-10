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

    void install_data() override;

    void install_reaction(std::function<void()> _reaction) override;

    void operator()(void *_obj) override;

    const std::string& classname() const noexcept override;

    ~RocketAttack() override = default;

private:
    Unit __get_random_unit_of_ship(const Field &_sm) noexcept;
    std::uint8_t __get_random_index_of_segments(const Ship &_ship) noexcept;

};

} // seagame


#endif // _ROCKET_ATTACK_H

