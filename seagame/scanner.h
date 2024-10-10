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
    explicit Scanner(const Unit &_unit); // left up
    Scanner(std::uint64_t _x, std::uint64_t _y);
    Scanner();
    
    void install_data(const Unit &_unit) override;

    void install_reaction(std::function<void()> _reaction) override;

    void operator()(void *_obj) override;

    const std::string& classname() const noexcept override;
    
    ~Scanner() override = default;

private:
    Unit _unit;
    std::function<void()> _reaction;

};

} // seagame


#endif // _SCANNER_H

