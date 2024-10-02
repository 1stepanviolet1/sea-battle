#include "../scanner.h"


namespace seagame
{

Scanner::Scanner(Unit _unit)
    : _unit(_unit)
{
    if (_unit.x() < 1 || _unit.y() < 1)
        throw std::invalid_argument("bad unit");

}

Scanner::Scanner(std::uint64_t _x, std::uint64_t _y)
    : Scanner(Unit(_x, _y))
{    }


void 
Scanner::operator()(void *_obj)
{
    Field &_fd = *static_cast<Field*>(_obj);


}

} // seagame

