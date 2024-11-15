#pragma once


#ifndef _SKILL_H
#define _SKILL_H

#include <stdexcept>
#include <string>
#include <functional>

#include "iSkill.h"
#include "unit.h"
#include "skill_name.h"

namespace seagame
{

class Field;

class Skill : public iSkill 
{
public:
    explicit Skill(std::shared_ptr<_last_skill_result> _last_res);

    inline void use(Field &_fd) override
    { return this->__use(&_fd); }

    std::shared_ptr<_last_skill_result> result() const noexcept override;

private:
    inline void __use(Void *_obj)
    { return (*this)(_obj); }

protected:
    std::shared_ptr<_last_skill_result> _last_res;

};

} // seagame


#endif // _SKILL_H

