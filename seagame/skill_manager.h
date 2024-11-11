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
private:
    SkillProduction _skill_production;
    std::queue<std::shared_ptr<iSkillFactory>> _queue_of_skills;
public:

    SkillManager();

    SkillManager(const SkillManager &other);
    SkillManager(SkillManager &&other) noexcept;

    ~SkillManager() = default;

    SkillManager& operator=(const SkillManager &other);
    SkillManager& operator=(SkillManager &&other) noexcept;

    void produce_skill(SkillName _sname);
    void produce_skill();

    SkillName front_skill() const noexcept;

    std::shared_ptr<iSkillFactory> extract_skill();

    bool empty() const noexcept;

private:
    std::vector<SkillName> __get_random_skills() const noexcept;

};

} // seagame


#endif // _SKILL_MANAGER_H

