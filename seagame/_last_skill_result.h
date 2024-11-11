#pragma once


#ifndef _LAST_SKILL_RESULT_H
#define _LAST_SKILL_RESULT_H

#include <cstdint>

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

}


#endif // _LAST_SKILL_RESULT_H

