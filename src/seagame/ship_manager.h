#pragma once


#ifndef _SHIP_MANAGER_H
#define _SHIP_MANAGER_H

#include <vector>
#include <cstdint>

#include "ship.h"


namespace seagame
{

class ShipManager
{
public:
    ShipManager(std::initializer_list<Ship::Len> _lens);
    ShipManager();
    ShipManager(const ShipManager &other);
    ShipManager(ShipManager &&other) noexcept;

    ~ShipManager() = default;

    ShipManager& operator=(const ShipManager &other);
    ShipManager& operator=(ShipManager &&other) noexcept;

    std::size_t new_ship(Ship::Len _len, Ship::Orientation _orie);
    
    Ship& operator[](std::uint64_t _id);
    const Ship& operator[](std::size_t _id) const;

    std::size_t amt() const noexcept;

private:
    std::vector<Ship> _container;
    // если кораблям понадобятся идентификаторы, то взять за таковые индексы в векторе

};

} // seagame


#endif // _SHIP_MANAGER_H

