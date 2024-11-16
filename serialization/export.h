#pragma once


#ifndef _EXPORT_H
#define _EXPORT_H

#include "dll_def.h"

#include <functional>

#include "json.h"


namespace seagame
{

extern "C" SERIALIZATION_API void
json_save(const nlohmann::json &_json, const std::string &_filename);

extern "C" SERIALIZATION_API nlohmann::json
json_load(const std::string &_filename);

} // seagame


#endif // _EXPORT_H

