#pragma once


#ifndef _SCANNER_H
#define _SCANNER_H

#include <vector>

#include "unit.h"
#include "iSkill.h"
#include "field.h"

namespace seagame
{

class Scanner : public iSkill
{
public:
    Scanner(const Unit &_unit); // left up
    Scanner(std::uint64_t _x, std::uint64_t _y);

    void operator()(void *_obj) override;
    
    const std::vector<Unit>& result() const noexcept;

    ~Scanner() override = default;

private:
    Unit _unit;
    std::vector<Unit> _result;
};

} // seagame


#endif // _SCANNER_H

