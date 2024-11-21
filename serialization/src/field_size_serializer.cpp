#include "field_size_serializer.h"


namespace seagame
{

void 
FieldSizeSerializer::operator()(Void *_obj)
{
    Field::Size &size = static_cast<Field::Size&>(*_obj);
    
    this->_json["_m"] = size.m();
    this->_json["_n"] = size.n();

}

} // seagame

