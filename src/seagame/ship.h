#pragma once


#ifndef _SHIP_HPP
#define _SHIP_HPP

#include <cstdint>
#include <vector>

namespace seagame
{

class Ship
{
public:
    enum Orientation;
    enum Integrity;

private:
    std::uint8_t _len;
    Orientation _orientation;
    std::vector<Integrity> _segments;

public:
    Ship(std::uint8_t _len, Orientation _orie);
    Ship(const Ship &other);
    Ship(Ship&&);

    Ship& operator=(const Ship &other);
    Ship& operator=(Ship&&);

    void hit(std::uint8_t _i);
    std::uint8_t len() const noexcept;
    const Orientation& orientation() const noexcept;
    const std::vector<Integrity>& segments() const noexcept;

};

}


#endif // _SHIP_HPP
