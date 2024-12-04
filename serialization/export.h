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

#include "field_loader.h"
#include "game_state_loader.h"
#include "ship_manager_loader.h"
#include "ship_loader.h"
#include "skill_manager_loader.h"
#include "unit_loader.h"

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


extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_field(const nlohmann::json &_json, ShipManager &_ship_manager);

extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_game_state(const nlohmann::json &_json);

extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_ship_manager(const nlohmann::json &_json);

extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_ship(const nlohmann::json &_json);

extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_skill_manager(const nlohmann::json &_json);

extern "C" SERIALIZATION_API std::shared_ptr<Owner>
load_unit(const nlohmann::json &_json);

} // seagame


#endif // _EXPORT_H

