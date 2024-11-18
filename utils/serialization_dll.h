#pragma once


#ifndef _SERIALIZATION_DLL_H
#define _SERIALIZATION_DLL_H

#include "nlohmann/json.hpp"

#include "dll.h"

namespace seagame
{

typedef void (*JsonSaver)(const nlohmann::json&, const std::string&);
typedef nlohmann::json (*JsonLoader)(const std::string&);

class SerializationDll : public DLL
{
public:
    SerializationDll();

    JsonSaver get_json_saver() const;
    JsonLoader get_json_loader() const;

};

} // seagame


#endif // _SERIALIZATION_DLL_H

