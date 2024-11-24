#pragma once


#ifndef _UNIT_SERIALIZER_H
#define _UNIT_SERIALIZER_H

#include "serializer.h"
#include "unit.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(Unit) 
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _UNIT_SERIALIZER_H

