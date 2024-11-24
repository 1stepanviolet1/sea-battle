#include "serializer.h"


namespace seagame
{

void 
_GET_SERIALIZER_NAME()::save(Owner *_ow)
{ return (*this)(_ow); }

const nlohmann::json& 
_GET_SERIALIZER_NAME()::get() const noexcept
{ return _json; }

} // seagame

