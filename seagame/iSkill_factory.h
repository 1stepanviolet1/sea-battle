#pragma once


#ifndef _iSKILL_FACTORY_H
#define _iSKILL_FACTORY_H

#include <memory>

#include "iSkill.h"
#include "unit.h"
#include "skill_name.h"
#include "owner.h"

namespace seagame
{

class iSkillFactory : public Owner
{
public:
    virtual std::shared_ptr<iSkill> create(const Unit& _unit = Unit()) = 0;
    virtual SkillName skillname() const noexcept = 0;

    virtual ~iSkillFactory() = 0;

};

} // seagame


#endif // _iSKILL_FACTORY_H

