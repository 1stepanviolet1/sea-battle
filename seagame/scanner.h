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
    Scanner(std::shared_ptr<_last_skill_result> _last_res, const Unit &_unit); // left up
    Scanner(std::shared_ptr<_last_skill_result> _last_res, std::uint64_t _x, std::uint64_t _y);
    Scanner();

    void operator()(void *_obj) override;

    SkillName skillname() const noexcept override;
    
    ~Scanner() override = default;

private:
    Unit _unit;

};

} // seagame


#endif // _SCANNER_H

