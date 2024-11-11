#pragma once


#ifndef _SKILL_FACTORY_H
#define _SKILL_FACTORY_H

#include "iSkill_factory.h"
#include "_last_skill_result.h"

namespace seagame
{

class SkillFactory : public iSkillFactory
{
public:
	SkillFactory(_last_skill_result &_last_res);

protected:
	_last_skill_result& _last_res;
};

}


#endif // _SKILL_FACTORY_H

