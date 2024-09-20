#pragma once


#ifndef _UNIT_H
#define _UNIT_H

#include <cstdint>

namespace seagame
{

class Unit
{
public:
    enum State
    {
        UNDEFINED,
        EMPTY,
        SHIP
    };

private:
    std::uint64_t _x;
    std::uint64_t _y;
    State _state;

public:
    explicit Unit(std::uint64_t x, std::uint64_t y, State state);
    explicit Unit(std::uint64_t x, std::uint64_t y);

    Unit(const Unit &other);
    Unit(Unit &&other) noexcept;

    ~Unit() = default;

    Unit& operator=(const Unit &other);
    Unit& operator=(Unit &&other) noexcept;

    std::uint64_t x() const noexcept;
    std::uint64_t y() const noexcept;
    const State& state() const noexcept;

};

} // seagame


#endif // _UNIT_H
