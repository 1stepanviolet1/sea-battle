#pragma once


#ifndef _SERIALIZATION_DLL_H
#define _SERIALIZATION_DLL_H

#include "nlohmann/json.hpp"

#include "dll.h"

typedef void(*JsonSaver)(const nlohmann::json&, const std::string&);
typedef nlohmann::json(*JsonLoader)(const std::string&);

namespace seagame
{

class SerializationDll : public DLL
{

};

} // seagame


#endif // _SERIALIZATION_DLL_H

