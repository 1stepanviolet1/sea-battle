#pragma once


#ifndef _SCANNER_H
#define _SCANNER_H

#include <vector>

#include "unit.h"
#include "field.h"

namespace seagame
{

class Scanner : public iSkill
{
public:
    explicit Scanner(const Unit &_unit); // left up
    Scanner(std::uint64_t _x, std::uint64_t _y);
    Scanner();
    
    void install_data(const Unit &_unit) override;

    void operator()(void *_obj) override;

    const std::string& __classname__() const noexcept override;
    
    const std::vector<Unit>& result() const noexcept; // TODO: will be delete

    ~Scanner() override = default;

private:
    Unit _unit;
    std::vector<Unit> _result;
};

} // seagame


#endif // _SCANNER_H

