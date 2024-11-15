#pragma once


#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "nlohmann/json.hpp"

#include "visitor.h"
#include "owner.h"

using json = nlohmann::json;

namespace seagame
{

class Serializer : public Visitor
{
protected:
    json __json;

public:
    Serializer();

    void load(Owner *_ow)
    { return (*this)(_ow); }

    const json& get() { return __json; }

protected:
    json& _json() { return __json; }

};

} // seagame


#endif // _SERIALIZER_H

