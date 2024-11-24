#pragma once


#ifndef _SHIP_MANAGER_SERIALIZER_H
#define _SHIP_MANAGER_SERIALIZER_H

#include "ship_serializer.h"
#include "ship_manager.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(ShipManager) 
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

private:
    _GET_SERIALIZER_NAME(Ship) ship_serializer;

};

} // seagame


#endif // _SHIP_MANAGER_SERIALIZER_H

