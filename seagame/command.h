#pragma once


#ifndef _COMMAND_H
#define _COMMAND_H

namespace seagame
{

class Command
{
public:
    virtual void exec() = 0;

    virtual ~Command() = 0;

};

} // seagame


#endif // _COMMAND_H

