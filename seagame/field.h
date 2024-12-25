#pragma once


#ifndef _FIELD_H
#define _FIELD_H

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <stdexcept>
#include <memory>

#include "unit.h"
#include "ship.h"
#include "owner.h"
#include "iSkill.h"
#include "command.h"

namespace seagame
{

class RocketAttack;
class Scanner;

class SetupReactOfDestroyedShip;

class FieldSerializer;
class FieldLoader;

class Field : public Owner
{
    friend RocketAttack;
    friend Scanner;
    friend SetupReactOfDestroyedShip;

    friend FieldSerializer;
    friend FieldLoader;

public:
    void test()
    {
        for (auto &pair : this->_deployed_ships)
        {
            std::cout << "ID: " << pair.second.get().id() << std::endl;
        }
    }

    class Size : public Owner
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

    std::unordered_map<Unit, std::reference_wrapper<Ship>> _deployed_ships;
private:
    std::unordered_set<Unit> _hit_units;
    std::unordered_set<Unit> _unusable_units;

    Size _size;

    std::shared_ptr<Command> _react_of_destroyed_ship;

public:
    explicit Field(std::uint64_t _m, std::uint64_t _n);
    explicit Field(Size _size);

    Field(const Field &other);
    Field(Field &&other) noexcept;

    ~Field() override = default;

    Field& operator=(const Field &other);
    Field& operator=(Field &&other) noexcept;

    void add_ship(Ship &_ship, const Unit &_unit);
    void add_ship(Ship &_ship, std::uint64_t _x, std::uint64_t y);

    void shot(const Unit &_unit);
    void shot(std::uint64_t _x, std::uint64_t _y);

    void accept_skill(std::shared_ptr<iSkill> _skill);

    const Size& size() const noexcept;
    const Size& size(const Size &_size) noexcept;

private:
    void __block_unit(const Unit &_unit, const Ship::Orientation &_orie, bool _flag);
    void __block_units(const Unit &_unit, const Ship &_ship, bool _flag);
    void __block_units_for_add(const Unit &_unit, const Ship &_ship);
    void __block_units_for_hit(const Unit &_unit, const Ship &_ship);

    bool __is_valid_unit(const Unit &_u) const noexcept;
    bool __is_valid_unit(std::uint64_t _x, std::uint64_t _y) const noexcept;
    
    bool __is_same_ship(const Unit &_lu, const Unit &_unit, std::uint8_t _offset) const noexcept;
    
    Unit __get_lu_seg_of_ship(const Unit &_unit, const Ship::Orientation &_orie, std::uint8_t &i) const noexcept;
    Unit __get_unit_of_valid_ship(const Unit &_unit, std::uint8_t &_i) const noexcept;
};

} // seagame


#endif // _FIELD_H

