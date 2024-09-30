#pragma once


#ifndef _DOUBLE_HIT_H
#define _DOUBLE_HIT_H

#include "unit.h"
#include "field.h"

namespace seagame
{

class DoubleHit : public iSkill
{
public:
    DoubleHit(const Unit &_unit);
    DoubleHit();

    void operator()(void *_obj) override;
    
    ~DoubleHit() override = default;

private:
    Unit _unit;
};

} // seagame


#endif // _DOUBLE_HIT_H

