#pragma once


#ifndef _iSKILL_FACTORY_H
#define _iSKILL_FACTORY_H

#include <memory>

#include "iSkill.h"
#include "unit.h"
#include "__plug_for_react.h"

namespace seagame
{

class iSkillFactory
{
public:
    virtual std::shared_ptr<iSkill> create(const Unit &_unit = Unit(), 
                                           const std::function<void(const Unit&)> &_funct = __plug_for_react()) = 0;

    virtual ~iSkillFactory() = 0;

};

} // seagame


#endif // _iSKILL_FACTORY_H

