#pragma once


#ifndef _SKILL_NAME_H
#define _SKILL_NAME_H

#include <ostream>

namespace seagame
{

enum SkillName
{
    DOUBLEHIT = 'D',
    ROCKETATTACK = 'R',
    SCANNER = 'S'
};

} // seagame


std::ostream& operator<<(std::ostream& os, seagame::SkillName &sn);


#endif // _SKILL_NAME_H

