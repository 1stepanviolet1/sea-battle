#include "../skill_name.h"


namespace std
{

ostream&
operator<<(ostream& os, seagame::SkillName &sn)
{
    switch (sn)
    {
    case seagame::SkillName::DOUBLEHIT:
        os << "Double_hit";
        break;
    
    case seagame::SkillName::ROCKETATTACK:
        os << "Rocket_attack";
        break;
    
    case seagame::SkillName::SCANNER:
        os << "Scanner";
        break;
    
    default:
        throw std::logic_error("Bad skill name");

    }

    return os;

}

} // std

