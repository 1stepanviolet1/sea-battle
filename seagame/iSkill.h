#pragma once


#ifndef _iSKILL_H
#define _iSKILL_H

#include <stdexcept>

#include "visitor.h"
#include "unit.h"
#include "skill_name.h"
#include "_last_skill_result.h"

namespace seagame
{

class Field;

class iSkill : public Visitor 
{
public:
    virtual inline void use(Field &_fd) = 0;

    virtual SkillName skillname() const noexcept = 0;

    virtual std::shared_ptr<_last_skill_result> result() const noexcept = 0;

};

} // seagame


#endif // _iSKILL_H

