#include "_last_skill_result.h"


namespace seagame
{

_last_skill_result::_last_skill_result() 
	: _status(SkillResultStatus::NONE)
{    }

SkillResultStatus 
_last_skill_result::get() const noexcept
{ return this->_status; }

void 
_last_skill_result::set(SkillResultStatus _status) noexcept
{
	this->_status = _status;

}

}

