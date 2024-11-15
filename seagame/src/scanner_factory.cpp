#include "../scanner_factory.h"

#include <string>
#include <functional>
#include <stdexcept>


namespace seagame
{

ScannerFactory::ScannerFactory(std::shared_ptr<_last_skill_result> _last_res)
    : SkillFactory(_last_res)
{    }

ScannerFactory::ScannerFactory()
    : ScannerFactory(std::make_shared<_last_skill_result>())
{    }

std::shared_ptr<iSkill>
ScannerFactory::create(const Unit &_unit)
{ return std::make_shared<Scanner>(_last_res, _unit); }


SkillName 
ScannerFactory::skillname() const noexcept
{ return SkillName::SCANNER; }

} // seagame

