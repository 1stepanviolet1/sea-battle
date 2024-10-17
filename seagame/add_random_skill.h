#pragma once


#ifndef _ADD_RANDOM_SKILL_H
#define _ADD_RANDOM_SKILL_H

#include "command.h"
#include "skill_manager.h"

namespace seagame
{

class AddRandomSkill : public Command
{
public:
    explicit AddRandomSkill(SkillManager &_sm);

    void exec() override;
    
    ~AddRandomSkill() override = default;

private:
    SkillManager &_skill_manager;
    
};

} // seagame


#endif // _ADD_RANDOM_SKILL_H

