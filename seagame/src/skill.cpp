#include "../skill.h"


namespace seagame
{

Skill::Skill(std::shared_ptr<_last_skill_result> _last_res)
	: _last_res(_last_res)
{    }

std::shared_ptr<_last_skill_result>
Skill::result() const noexcept
{ return this->_last_res; }

} // seagame

