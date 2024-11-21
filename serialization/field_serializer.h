#pragma once


#ifndef _FIELD_SERIALIZER_H
#define _FIELD_SERIALIZER_H

#include "field_size_serializer.h"
#include "unit_serializer.h"

namespace seagame
{

class SERIALIZATION_API FieldSerializer : public Serializer
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _FIELD_SERIALIZER_H

