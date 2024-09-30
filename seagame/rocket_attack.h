#pragma once


#ifndef _ROCKET_ATTACK_H
#define _ROCKET_ATTACK_H

#include <random>

#include "ship_manager.h"

namespace seagame
{

class RocketAttack : public iSkill
{
private:
    ShipManager &_sm;
    std::random_device rd;

public:
    RocketAttack(ShipManager &_sm);

    void operator()(void *_obj) override;

    ~RocketAttack() override = default;

private:
    std::size_t __get_random_index_of_ship() const noexcept;
    std::uint8_t __get_random_index_of_segments(const Ship &_ship) const noexcept;

};

} // seagame


#endif // _ROCKET_ATTACK_H

