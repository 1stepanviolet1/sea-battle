#pragma once


#ifndef _VISITOR_H
#define _VISITOR_H

#include "void.h"

namespace seagame
{

class Visitor : public Void
{
public:
    virtual void operator()(Void *_obj) = 0;

    virtual ~Visitor() = 0;
};

} // seagame


#endif // _VISITOR_H

