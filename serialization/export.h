#pragma once


#ifndef _EXPORT_H
#define _EXPORT_H

#include "dll_def.h"

#include <functional>

#include "json.h"

#include "field_serializer.h"
#include "game_state_serializer.h"
#include "ship_manager_serializer.h"
#include "ship_serializer.h"
#include "skill_manager_serializer.h"
#include "unit_serializer.h"

namespace seagame
{

extern "C" SERIALIZATION_API void
json_save(const nlohmann::json &_json, const std::string &_filename);

extern "C" SERIALIZATION_API nlohmann::json
json_load(const std::string &_filename);


extern "C" SERIALIZATION_API nlohmann::json
serialize_field(Field &_field);

extern "C" SERIALIZATION_API nlohmann::json
serialize_game_state(GameState &_game_state);

extern "C" SERIALIZATION_API nlohmann::json
serialize_ship_manager(ShipManager &_ship_manager);

extern "C" SERIALIZATION_API nlohmann::json
serialize_ship(Ship &_ship);

extern "C" SERIALIZATION_API nlohmann::json
serialize_skill_manager(SkillManager &_skill_manager);

extern "C" SERIALIZATION_API nlohmann::json
serialize_unit(Unit &_unit);

} // seagame


#endif // _EXPORT_H

