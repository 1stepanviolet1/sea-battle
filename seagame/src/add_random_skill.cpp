#include "../add_random_skill.h"


namespace seagame
{

AddRandomSkill::AddRandomSkill(SkillManager &_sm)
    : _skill_manager(_sm)
{    }


void
AddRandomSkill::exec()
{
    this->_skill_manager.produce_skill();

}

} // seagame

