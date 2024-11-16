#include "../serializer.h"


namespace seagame
{

Serializer::Serializer()
    : _json()
{    }

void 
Serializer::load(Owner *_ow)
{ return (*this)(_ow); }

const json& 
Serializer::get() const noexcept
{ return _json; }

} //  seagame

