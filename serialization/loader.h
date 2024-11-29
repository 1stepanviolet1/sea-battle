#pragma once


#ifndef _LOADER_H
#define _LOADER_H

#include "dll_def.h"

#include "nlohmann/json.hpp"

#include "owner.h"

namespace seagame
{

class SERIALIZATION_API _GET_LOADER_NAME() 
    : public Owner
{
protected:
    Owner *_obj;

public:
    virtual void load(const nlohmann::json &_json) = 0;

    Owner* get() const noexcept;

    ~_GET_LOADER_NAME()() override = default;

};

} // seagame

#define REG_SIMPLE_LOADER_FOR(_NAME)                    \
    class SERIALIZATION_API _GET_LOADER_NAME(_NAME)     \
    : public _GET_LOADER_NAME()                         \
    {                                                   \
    public:                                             \
        void load(const nlohmann::json &_json) override;\
    };


#endif // _LOADER_H

