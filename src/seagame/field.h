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
    class Size
    {
    public:
        explicit Size(std::uint64_t m, std::uint64_t n);

        Size(const Size &other);
        Size(Size &&other) noexcept;

        ~Size() = default;

        Size& operator=(const Size &other);
        Size& operator=(Size &&other) noexcept;

        std::uint64_t m() const noexcept;
        std::uint64_t n() const noexcept;

    private:
        std::uint64_t _m;
        std::uint64_t _n;
    };

private:
    std::unordered_map<Unit, std::reference_wrapper<Ship>> _deployed_ships;
    std::unordered_set<Unit> _hit_units;
    std::unordered_set<Unit> _unusable_units;

    Size _size;

public:
    explicit Field(std::uint64_t m, std::uint64_t n);
    Field(Size size);

    Field(const Field &other);
    Field(Field &&other) noexcept;

    ~Field() = default;

    Field& operator=(const Field &other);
    Field& operator=(Field &&other) noexcept;

    void add_ship(Ship &_ship, std::uint64_t x, std::uint64_t y);
    void add_ship(Ship &_ship, const Unit &_unit);

    void shot(std::uint64_t x, std::uint64_t y);
    void shot(const Unit &_unit);

    const Size& size() const noexcept;
    
};

} // seagame


#endif // _FIELD_H
