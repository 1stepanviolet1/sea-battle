#pragma once


#ifndef _VISITOR_H
#define _VISITOR_H

namespace seagame
{

class Visitor
{
public:
    virtual void operator()(void *_obj) = 0;

    virtual ~Visitor() = 0;
};

} // seagame


#endif // _VISITOR_H

