#pragma once


#ifndef _SKILL_MANAGER_H
#define _SKILL_MANAGER_H

#include <queue>
#include <memory>

#include "skill_production.h"

namespace seagame
{

class SkillManager
{
public:
    SkillManager();

    SkillManager(const SkillManager &other);
    SkillManager(SkillManager &&other) noexcept;

    ~SkillManager() = default;

    SkillManager& operator=(const SkillManager &other);
    SkillManager& operator=(SkillManager &&other) noexcept;

    void produce_skill(SkillName _sname);

    SkillName front_skill() const noexcept;

    std::shared_ptr<iSkillFactory> extract_skill();

    bool empty() const noexcept;

private:
    SkillProduction _skill_production;
    std::queue<std::shared_ptr<iSkillFactory>> _queue_of_skills;

};

} // seagame


#endif // _SKILL_MANAGER_H

