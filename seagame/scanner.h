#pragma once


#ifndef _SCANNER_H
#define _SCANNER_H

#include <vector>

#include "unit.h"
#include "field.h"
#include "skill.h"

namespace seagame
{

class Scanner : public Skill
{
public:
    Scanner(const Unit &_unit, const std::function<void(const Unit&)> _funct); // left up
    Scanner(std::uint64_t _x, std::uint64_t _y, const std::function<void(const Unit&)> _funct);
    Scanner();

    void operator()(void *_obj) override;

    SkillName classname() const noexcept override;
    
    ~Scanner() override = default;

private:
    Unit _unit;
    std::function<void(const Unit&)> _reaction;

};

} // seagame


#endif // _SCANNER_H

