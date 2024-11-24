#pragma once


#ifndef _FIELD_SERIALIZER_H
#define _FIELD_SERIALIZER_H

#include "field_size_serializer.h"
#include "unit_serializer.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(Field) 
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

private:
    _GET_SERIALIZER_NAME(FieldSize) field_size_serializer;
    _GET_SERIALIZER_NAME(Unit) unit_serializer;

};

} // seagame


#endif // _FIELD_SERIALIZER_H

