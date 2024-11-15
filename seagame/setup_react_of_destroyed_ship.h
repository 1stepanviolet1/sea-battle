#pragma once


#ifndef _SETUP_REACT_OF_DESTROYED_SHIP_H
#define _SETUP_REACT_OF_DESTROYED_SHIP_H

#include <memory>

#include "visitor.h"
#include "command.h"
#include "field.h"

namespace seagame
{

class SetupReactOfDestroyedShip : public Visitor
{
public:
    explicit SetupReactOfDestroyedShip(std::shared_ptr<Command> _cmd);
    
    void operator()(Void *_obj) override;

    ~SetupReactOfDestroyedShip() override = default;

private:
    std::shared_ptr<Command> _cmd;

};

} // seagame


#endif // _SETUP_REACT_OF_DESTROYED_SHIP_H

