#pragma once


#ifndef _UNIT_H
#define _UNIT_H

#include <cstdint>
#include <functional>
#include <string>

#include "owner.h"

namespace seagame
{

class Unit : public Owner
{
public:
    enum State
    {
        UNDEFINED = '?',
        EMPTY = '-',
        SHIP = '*'
    };

private:
    std::uint64_t _x;
    std::uint64_t _y;
    State _state;

public:
    explicit Unit(std::uint64_t x, std::uint64_t y, State state);
    explicit Unit(std::uint64_t x, std::uint64_t y);
    Unit();

    Unit(const Unit &other);
    Unit(Unit &&other) noexcept;

    ~Unit() = default;

    Unit& operator=(const Unit &other);
    Unit& operator=(Unit &&other) noexcept;

    std::uint64_t x() const noexcept;
    std::uint64_t y() const noexcept;
    State state() const noexcept;

};

} // seagame


namespace std
{

template <>
struct hash<seagame::Unit>
{
    std::size_t operator()(const seagame::Unit& u) const;
};

template <>
struct equal_to<seagame::Unit>
{
    bool operator()(const seagame::Unit& lhs, const seagame::Unit& rhs) const;
};

template <>
struct hash<std::reference_wrapper<seagame::Unit>>
{
    std::size_t operator()(const std::reference_wrapper<seagame::Unit>& u) const;
};

template <>
struct equal_to<std::reference_wrapper<seagame::Unit>>
{
    bool operator()(const std::reference_wrapper<seagame::Unit>& lhs, const std::reference_wrapper<seagame::Unit>& rhs) const;
};

} // std


#endif // _UNIT_H
