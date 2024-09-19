#pragma once


#ifndef _FIELD_H
#define _FIELD_H

#include <unordered_map>
#include <unordered_set>
#include <functional>

#include "unit.h"
#include "ship_manager.h"

namespace seagame
{

class Field
{
public:
    explicit Field(std::uint64_t m, std::uint64_t n);

    Ship& add_ship(Ship _ship, std::uint64_t x, std::uint64_t y, Ship::Orientation _orie);
    Ship& add_ship(Ship _ship, Unit _unit, Ship::Orientation _orie);

    void shot(std::uint64_t x, std::uint64_t y);
    void shot(Unit _unit);

private:
    std::unordered_map<Unit, std::reference_wrapper<Ship>> _deployed_ships;
    std::unordered_set<Unit> _hited_units;
    std::unordered_set<Unit> _unusable_units;
    
};

} // seagame


#endif // _FIELD_H

