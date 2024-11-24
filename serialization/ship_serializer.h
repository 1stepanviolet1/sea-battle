#pragma once


#ifndef _SHIP_SERIALIZER_H
#define _SHIP_SERIALIZER_H

#include "serializer.h"
#include "ship.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(Ship)
    : public _GET_SERIALIZER_NAME()
{
public:
    void operator()(Void *_obj) override;

};

} // seagame


#endif // _SHIP_SERIALIZER_H

