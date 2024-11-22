#pragma once


#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "dll_def.h"

#include "nlohmann/json.hpp"

#include "visitor.h"
#include "owner.h"

namespace seagame
{

class SERIALIZATION_API Serializer : public Visitor
{
protected:
    nlohmann::json _json;

public:
    void save(Owner *_ow);

    const nlohmann::json& get() const noexcept;

    ~Serializer() override = default;

};

} // seagame


#endif // _SERIALIZER_H
