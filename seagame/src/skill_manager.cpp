#include "../skill_manager.h"
#include "../extract_error.h"

#include <random>
#include <vector>


namespace seagame 
{

SkillManager::SkillManager()
    : _skill_production(std::make_shared<_last_skill_result>())
{
    for (const auto &skillname : this->__get_random_skills())
        this->produce_skill(skillname);

}


SkillManager::SkillManager(const SkillManager &other)
    : _skill_production(other._skill_production), 
      _queue_of_skills(other._queue_of_skills)
{    }

SkillManager::SkillManager(SkillManager &&other) noexcept
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

void 
SkillManager::produce_skill()
{
    return this->produce_skill(
        this->__get_random_skills()[0]
    );
}

SkillName 
SkillManager::front_skill() const noexcept
{ return this->_queue_of_skills.front()->skillname(); }

std::shared_ptr<iSkillFactory> 
SkillManager::extract_skill()
{
    if (this->empty())
        throw ExtractError("Skills not found");

    std::shared_ptr<iSkillFactory> _front_skill = this->_queue_of_skills.front();
    this->_queue_of_skills.pop();
    return _front_skill;
}

bool 
SkillManager::empty() const noexcept
{ return this->_queue_of_skills.empty(); }


std::shared_ptr<_last_skill_result>
SkillManager::last_result() const noexcept
{ return this->_skill_production.last_result(); }


std::vector<SkillName> 
SkillManager::__get_random_skills() const noexcept
{
    std::vector<SkillName> _set_skills = {
        SkillName::DOUBLEHIT,
        SkillName::ROCKETATTACK,
        SkillName::SCANNER
    };

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(_set_skills.begin(), _set_skills.end(), rng);

    return _set_skills;

}

} // seagame 

