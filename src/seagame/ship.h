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
    enum Len;

private:
    Len _len;
    Orientation _orientation;
    std::vector<Integrity> _segments;

public:
    explicit Ship(Len _len, Orientation _orie);
    explicit Ship(Len _len);
    Ship();

    Ship(const Ship &other);
    Ship(Ship &&other) noexcept;

    ~Ship() = default;

    Ship& operator=(const Ship &other);
    Ship& operator=(Ship &&other) noexcept;

    void hit(std::uint8_t _i);
    
    const Len& len() const noexcept;
    const Orientation& orientation() const noexcept;
    const std::vector<Integrity>& segments() const noexcept;

};

} // seagame


#endif // _SHIP_HPP
