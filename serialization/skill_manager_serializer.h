#pragma once


#ifndef _SKILL_MANAGER_SERIALIZER_H
#define _SKILL_MANAGER_SERIALIZER_H

#include <queue>

#include "serializer.h"
#include "skill_manager.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(SkillManager) 
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _SKILL_MANAGER_SERIALIZER_H

