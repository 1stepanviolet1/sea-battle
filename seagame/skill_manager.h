#pragma once


#ifndef _SKILL_MANAGER_H
#define _SKILL_MANAGER_H

#include <queue>
#include <memory>
#include <type_traits>

#include "iSkill.h"
#include "double_hit.h"
#include "rocket_attack.h"
#include "scanner.h"

class SkillManager
{
public:
    SkillManager();

    SkillManager(const SkillManager &other);
    SkillManager(SkillManager &&other) noexcept;

    ~SkillManager() = default;

    SkillManager& operator=(const SkillManager &other);
    SkillManager& operator=(SkillManager &&other) noexcept;

    template <class T, class ...Args_T>
    typename std::enable_if<
        std::is_same_v<T, DoubleHit>
     && std::is_same_v<T, RocketAttak>
     && std::is_same_v<T, Scanner>
    >::type
    add_skill(Args_T ..._args)
    {
        this->_queue_of_skills.push(
            std::make_shared<T>(_args...);
        );
    }

    

private:
    std::queue<std::shared_ptr<iSkill>> _queue_of_skills;

};


#endif // _SKILL_MANAGER_H
