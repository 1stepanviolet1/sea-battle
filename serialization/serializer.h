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

    void load(Owner *_ow);

    const json& get() const noexcept;

};

} // seagame


#endif // _SERIALIZER_H

