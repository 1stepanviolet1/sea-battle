#pragma once


#ifndef _SERIALIZATION_DLL_H
#define _SERIALIZATION_DLL_H

#include "nlohmann/json.hpp"

#include "dll.h"

#define _GET_SERIALIZER_NAME(CLASS) CLASS##Serializer_t

#define REG_SERIALIZER_FUNCT_TYPE(CLASS) \
    typedef nlohmann::json (*_GET_SERIALIZER_NAME(CLASS))(CLASS&)

#define REG_GETTER_FOR(CLASS, _NAME) \
    _GET_SERIALIZER_NAME(CLASS) _GETTER(_NAME)() const

#define GET_NAME_OF_FUNCT_FROM_SERIALIZE(_NAME) "serialize_"#_NAME

namespace seagame
{

class Field;
class GameState;
class ShipManager;
class Ship;
class SkillManager;
class Unit;

typedef void (*JsonSaver)(const nlohmann::json&, const std::string&);
typedef nlohmann::json (*JsonLoader)(const std::string&);

REG_SERIALIZER_FUNCT_TYPE(Field);
REG_SERIALIZER_FUNCT_TYPE(GameState);
REG_SERIALIZER_FUNCT_TYPE(ShipManager);
REG_SERIALIZER_FUNCT_TYPE(Ship);
REG_SERIALIZER_FUNCT_TYPE(SkillManager);
REG_SERIALIZER_FUNCT_TYPE(Unit);

class _GET_DLL_NAME(Serialization) : public _GET_DLL_NAME()
{
public:
    _GET_DLL_NAME(Serialization)();

    JsonSaver _GETTER(json_saver)() const;
    JsonLoader _GETTER(json_loader)() const;

    REG_GETTER_FOR(Field, field_serializer);
    REG_GETTER_FOR(GameState, game_state_serializer);
    REG_GETTER_FOR(ShipManager, ship_manager_serializer);
    REG_GETTER_FOR(Ship, ship_serializer);
    REG_GETTER_FOR(SkillManager, skill_manager_serializer);
    REG_GETTER_FOR(Unit, unit_serializer);

};

} // seagame


#endif // _SERIALIZATION_DLL_H

