#pragma once


#ifndef _SHIP_MANAGER_SERIALIZER_H
#define _SHIP_MANAGER_SERIALIZER_H

#include "ship_serializer.h"
#include "ship_manager.h"

namespace seagame
{

class SERIALIZATION_API ShipManagerSerializer : public Serializer
{
public:
    void operator()(Void *_obj) override;

private:
    ShipSerializer ship_serializer;

};

} // seagame


#endif // _SHIP_MANAGER_SERIALIZER_H

