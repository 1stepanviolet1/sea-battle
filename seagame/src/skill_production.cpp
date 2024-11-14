#include "../skill_production.h"


namespace seagame
{

SkillProduction::SkillProduction(std::shared_ptr<_last_skill_result> _last_res)
    : _last_res(_last_res)
{
    this->_double_hit_factory = std::make_shared<DoubleHitFactory>(this->_last_res);
    this->_rocket_attack_factory = std::make_shared<RocketAttackFactory>(this->_last_res);
    this->_scanner_factory = std::make_shared<ScannerFactory>(this->_last_res);
    
}

SkillProduction::SkillProduction()
    : SkillProduction(std::make_shared<_last_skill_result>())
{    }


SkillProduction::SkillProduction(const SkillProduction &other)
    : _double_hit_factory(other._double_hit_factory), 
      _rocket_attack_factory(other._rocket_attack_factory), 
      _scanner_factory(other._scanner_factory),
      _last_res(other._last_res)
{    }

SkillProduction::SkillProduction(SkillProduction &&other) noexcept
    : _double_hit_factory(std::move(other._double_hit_factory)), 
      _rocket_attack_factory(std::move(other._rocket_attack_factory)), 
      _scanner_factory(std::move(other._scanner_factory)),
      _last_res(std::move(other._last_res))
{    }


SkillProduction& 
SkillProduction::operator=(const SkillProduction &other)
{
    if (this == &other)
    {
        this->_double_hit_factory = other._double_hit_factory;
        this->_rocket_attack_factory = other._rocket_attack_factory;
        this->_scanner_factory = other._scanner_factory;
        this->_last_res = other._last_res;
    }
    return *this;
}

SkillProduction& 
SkillProduction::operator=(SkillProduction &&other) noexcept
{
    if (this == &other)
    {
        this->_double_hit_factory = std::move(other._double_hit_factory);
        this->_rocket_attack_factory = std::move(other._rocket_attack_factory);
        this->_scanner_factory = std::move(other._scanner_factory);
        this->_last_res = std::move(other._last_res);
    }
    return *this;
}


std::shared_ptr<iSkillFactory> 
SkillProduction::get_factory(SkillName _sn) const
{
    switch (_sn)
    {
        case SkillName::DOUBLEHIT:
            return this->_double_hit_factory;

        case SkillName::ROCKETATTACK:
            return this->_rocket_attack_factory;

        case SkillName::SCANNER:
            return this->_scanner_factory;
        
        default:
            throw std::logic_error("bad skill name");

    }

}

std::shared_ptr<_last_skill_result>
SkillProduction::last_result() const noexcept
{ return this->_last_res; }

} // seagame

