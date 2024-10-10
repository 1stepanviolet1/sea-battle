#pragma once


#ifndef _DOUBLE_HIT_H
#define _DOUBLE_HIT_H

#include <type_traits>

#include "unit.h"
#include "field.h"
#include "skill.h"

namespace seagame
{

class DoubleHit : public Skill
{
public:
    explicit DoubleHit(const Unit &_unit);
    DoubleHit(std::uint64_t _x, std::uint64_t _y);
    DoubleHit();

    void install_data(const Unit &_unit) override;

    void install_reaction(std::function<void()> _reaction) override;

    void operator()(void *_obj) override;

    const std::string& classname() const noexcept override;

    ~DoubleHit() override = default;

private:
    Unit _unit;

};

} // seagame


#endif // _DOUBLE_HIT_H

