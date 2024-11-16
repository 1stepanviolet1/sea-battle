#pragma once


#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "dll_def.h"

#include "nlohmann/json.hpp"

#include "visitor.h"
#include "owner.h"

using json = nlohmann::json;

namespace seagame
{

class SERIALIZATION_API Serializer : public Visitor
{
protected:
    json _json;

public:
    Serializer();

    void load(Owner *_ow);

    const json& get() const noexcept;

};

} // seagame


#endif // _SERIALIZER_H

