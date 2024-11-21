#pragma once


#ifndef _SHIP_SERIALIZER_H
#define _SHIP_SERIALIZER_H

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


#endif // _SHIP_SERIALIZER_H

