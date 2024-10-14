#pragma once


#ifndef ___PLUG_FOR_REACT_H
#define ___PLUG_FOR_REACT_H

#include <stdexcept>

#include "unit.h"

namespace seagame
{

class __plug_for_react
{
public:
    void operator()(const Unit &)
    { throw std::logic_error("__plug_for_react"); }

};

} // seagame


#endif // ___PLUG_FOR_REACT_H

