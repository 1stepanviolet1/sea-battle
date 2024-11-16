#include "serializer.h"


namespace seagame
{

void 
Serializer::load(Owner *_ow)
{ return (*this)(_ow); }

const nlohmann::json& 
Serializer::get() const noexcept
{ return _json; }

} //  seagame

