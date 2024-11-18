#pragma once


#ifndef _UNIT_SERIALIZER_H
#define _UNIT_SERIALIZER_H

#include "serializer.h"
#include "ship.h"

namespace seagame
{

class SERIALIZATION_API ShipSerializer : public Serializer
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _UNIT_SERIALIZER_H

