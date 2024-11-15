#include "../setup_react_of_destroyed_ship.h"


namespace seagame
{

SetupReactOfDestroyedShip::SetupReactOfDestroyedShip(std::shared_ptr<Command> _cmd)
    : _cmd(_cmd)
{    }


void 
SetupReactOfDestroyedShip::operator()(Void *_obj)
{
    Field &_fd = *static_cast<Field*>(_obj);
    _fd._react_of_destroyed_ship = this->_cmd;

}

} // seagame

