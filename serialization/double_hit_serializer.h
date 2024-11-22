#pragma once


#ifndef _DOUBLE_HIT_SERIALIZER_H
#define _DOUBLE_HIT_SERIALIZER_H

#include "unit_serializer.h"
#include "double_hit.h"

namespace seagame
{

class SERIALIZATION_API DoubleHitSerializer : public Serializer
{
public:
    void operator()(Void *_obj) override;

private:
    UnitSerializer unit_serializer;

};

} // seagame


#endif // _DOUBLE_HIT_SERIALIZER_H

