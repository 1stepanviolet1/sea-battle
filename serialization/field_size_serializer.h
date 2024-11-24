#pragma once


#ifndef _FIELD_SIZE_SERIALIZER_H
#define _FIELD_SIZE_SERIALIZER_H

#include "serializer.h"
#include "field.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(FieldSize) 
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _FIELD_SIZE_SERIALIZER_H

