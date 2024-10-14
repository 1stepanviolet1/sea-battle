#include "../skill_production.h"


namespace seagame
{

SkillProduction::SkillProduction()
{
    this->_dh = std::make_shared<DoubleHitFactory>();
    this->_ra = std::make_shared<RocketAttackFactory>();
    this->_sc = std::make_shared<ScannerFactory>();
    
}


SkillProduction::SkillProduction(const SkillProduction &other)
    : _dh(other._dh), _ra(other._ra), _sc(other._sc)
{    }

SkillProduction::SkillProduction(SkillProduction &&other) noexcept
    : _dh(std::move(other._dh)), _ra(std::move(other._ra)), _sc(std::move(other._sc))
{    }


SkillProduction& 
SkillProduction::operator=(const SkillProduction &other)
{
    if (this == &other)
    {
        this->_dh = other._dh;
        this->_ra = other._ra;
        this->_sc = other._sc;
    }
    return *this;
}

SkillProduction& 
SkillProduction::operator=(SkillProduction &&other) noexcept
{
    if (this == &other)
    {
        this->_dh = std::move(other._dh);
        this->_ra = std::move(other._ra);
        this->_sc = std::move(other._sc);
    }
    return *this;
}


std::shared_ptr<iSkillFactory> 
SkillProduction::get_factory(SkillName _sn) const noexcept
{
    switch (_sn)
    {
        case SkillName::DOUBLEHIT:
            return this->_dh;

        case SkillName::ROCKETATTACK:
            return this->_ra;

        case SkillName::SCANNER:
            return this->_sc;
        
        default:
            throw std::logic_error("bad skill name");

    }

}

} // seagame

