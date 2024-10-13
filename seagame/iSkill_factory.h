#pragma once


#ifndef _iSKILL_FACTORY_H
#define _iSKILL_FACTORY_H

#include <memory>

#include "iSkill.h"
#include "unit.h"

namespace seagame
{

class iSkillFactory
{
public:
    virtual std::shared_ptr<iSkill> operator()(const Unit &_unit, 
                                               const std::function<void(const Unit&)> _funct) = 0;

    virtual ~iSkillFactory() = 0;

};

} // seagame


#endif // _iSKILL_FACTORY_H

