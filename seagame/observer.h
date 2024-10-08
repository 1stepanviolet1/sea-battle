#pragma once


#ifndef _OBSERVER_H
#define _OBSERVER_H

namespace seagame
{

class Observer
{
public:
    virtual void notify() = 0;

    virtual ~Observer() = 0;
};

} // seagame


#endif // _OBSERVER_H\

