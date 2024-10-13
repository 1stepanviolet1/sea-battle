#pragma once


#ifndef _SKILL_NAME_H
#define _SKILL_NAME_H

#include <ostream>

namespace seagame
{

enum class SkillName : char
{
    DOUBLEHIT = 'D',
    ROCKETATTACK = 'R',
    SCANNER = 'S'
};

} // seagame


namespace std
{

ostream&
operator<<(ostream& os, seagame::SkillName &sn);

} // std


#endif // _SKILL_NAME_H

