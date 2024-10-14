#pragma once


#ifndef _DOUBLE_HIT_FACTORY_H
#define _DOUBLE_HIT_FACTORY_H

#include <memory>

#include "iSkill_factory.h"
#include "double_hit.h"

namespace seagame
{

class DoubleHitFactory : public iSkillFactory
{
public:
    std::shared_ptr<iSkill> create(const Unit &_unit, 
                                   const std::function<void(const Unit&)> _funct = [](auto){}) override;

    ~DoubleHitFactory() override = default;

};

} // seagame


#endif // _DOUBLE_HIT_FACTORY_H

