#pragma once


#ifndef _LAST_SKILL_RESULT_H
#define _LAST_SKILL_RESULT_H

#include <cstdint>
#include <iostream>

namespace seagame
{

enum class SkillResultStatus : std::uint16_t
{
    NONE,
    FOUND_SHIP,
    NOT_FOUND_SHIP,
    SUCCESS
};

class _last_skill_result
{
public:
	_last_skill_result();

    SkillResultStatus get() const noexcept;

    void set(SkillResultStatus _status) noexcept;

	~_last_skill_result() = default;

private:
	SkillResultStatus _status;

};

} // seagame


std::ostream& operator<<(std::ostream& os, seagame::SkillResultStatus _s);


#endif // _LAST_SKILL_RESULT_H

