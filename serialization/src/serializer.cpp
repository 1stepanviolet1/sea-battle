#include "../serializer.h"


namespace seagame
{

Serializer::Serializer()
    : __json()
{    }

void 
Serializer::load(Owner *_ow)
{ return (*this)(_ow); }

const json& 
Serializer::get() const noexcept
{ return __json; }

} //  seagame

