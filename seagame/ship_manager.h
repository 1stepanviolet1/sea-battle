#pragma once


#ifndef _SHIP_MANAGER_H
#define _SHIP_MANAGER_H

#include <vector>
#include <cstdint>
#include <type_traits>

#include "ship.h"


namespace seagame
{




class ShipManager
{
public:
    using ArrayOfLens = std::initializer_list<Ship::Len>;

private:
    std::vector<Ship> _container;
    // если кораблям понадобятся идентификаторы, то взять за таковые индексы в векторе

public:
    template <class T,
    typename std::void_t<
        typename std::remove_reference<T>::type::value_type,
        typename std::remove_reference<T>::type::iterator,
        typename std::remove_reference<T>::type::const_iterator
    >* = nullptr>
    ShipManager(const T &_lens)
    {
        static_assert(std::is_same<
            typename std::remove_reference<T>::type::value_type,
            Ship::Len
        >::value, "Container must contain seagame::Ship::Len");

        this->__construct(_lens);

    }

    ShipManager(const ArrayOfLens &_lens);

    ShipManager();

    ShipManager(const ShipManager &other);
    ShipManager(ShipManager &&other) noexcept;

    ~ShipManager() = default;

    ShipManager& operator=(const ShipManager &other);
    ShipManager& operator=(ShipManager &&other) noexcept;

    std::uint64_t new_ship(Ship::Len _len, Ship::Orientation _orie);
    std::uint64_t new_ship(Ship::Len _len);

    Ship& operator[](std::uint64_t _id);
    const Ship& operator[](std::uint64_t _id) const;

    const std::vector<Ship>& container() const noexcept;
    std::size_t amt() const noexcept;

private:
    template <class T>
    inline void __construct(const T &_lens)
    {
        for (const auto &_len : _lens)
            this->new_ship(_len);
    }

};

} // seagame


#endif // _SHIP_MANAGER_H
