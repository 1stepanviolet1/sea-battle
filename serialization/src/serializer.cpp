#include "../serialazer.h"


namespace seagame
{

Serializer::Serializer()
    : __json()
{    }

void 
Serializer::load(Owner *_ow)
{ return (*this)(_ow); }

const json& 
Serializer::get() 
{ return __json; }

json& 
Serializer::_json() 
{ return __json; }

} //  seagame

