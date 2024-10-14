#include "../skill_manager.h"


namespace seagame 
{

SkillManager::SkillManager()
{    } // TODO: 


SkillManager::SkillManager(const SkillManager &other)
    : _skill_production(other._skill_production), 
      _queue_of_skills(other._queue_of_skills)
{    }

SkillManager::SkillManager(SkillManager &&other)
    : _skill_production(std::move(other._skill_production)), 
      _queue_of_skills(std::move(other._queue_of_skills))
{    }


SkillManager& 
SkillManager::operator=(const SkillManager &other)
{
    if (this != &other)
    {
        this->_skill_production = other._skill_production;
        this->_queue_of_skills = other._queue_of_skills;
    }
    return *this;
}

SkillManager&
SkillManager::operator=(SkillManager &&other) noexcept
{
    if (this != &other)
    {
        this->_skill_production = std::move(other._skill_production);
        this->_queue_of_skills = std::move(other._queue_of_skills);
    }
    return *this;
}


void 
SkillManager::produce_skill(SkillName _sname)
{
    this->_queue_of_skills.push(
        this->_skill_production.get_factory(_sname)
    );
}

SkillName 
SkillManager::front_skill() const noexcept
{ return this->_queue_of_skills.front()->skillname(); }

std::shared_ptr<iSkillFactory> 
SkillManager::extract_skill()
{
    std::shared_ptr<iSkillFactory> _front_skill = this->_queue_of_skills.front();
    this->_queue_of_skills.pop();
    return _front_skill;
}

bool 
SkillManager::empty() const noexcept
{ return this->_queue_of_skills.empty(); }

} // seagame 

