#pragma once


#ifndef _SERIALIZATION_DLL_H
#define _SERIALIZATION_DLL_H

#include <memory>

#include "nlohmann/json.hpp"

#include "dll.h"

#define _GET_SERIALIZER_NAME(CLASS) CLASS##Serializer_t
#define _GET_LOADER_NAME(CLASS) CLASS##Loader_t

#define REG_SERIALIZER_FUNCT_TYPE(CLASS) \
    typedef nlohmann::json (*_GET_SERIALIZER_NAME(CLASS))(CLASS&)

#define REG_LOADER_FUNCT_TYPE(CLASS) \
    typedef std::shared_ptr<Owner> (*_GET_LOADER_NAME(CLASS))(const nlohmann::json&)

#define REG_GETTER_FOR_SERIALIZERS(CLASS, _NAME) \
    _GET_SERIALIZER_NAME(CLASS) _GETTER(_NAME)() const

#define REG_GETTER_FOR_LOADERS(CLASS, _NAME) \
    _GET_LOADER_NAME(CLASS) _GETTER(_NAME)() const

#define GET_NAME_OF_FUNCT_FROM_SERIALIZERS(_NAME) "serialize_"#_NAME
#define GET_NAME_OF_FUNCT_FROM_LOADERS(_NAME) "load_"#_NAME

namespace seagame
{

class Owner;

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

typedef std::shared_ptr<Owner> (*_GET_LOADER_NAME(Field))(const nlohmann::json&, ShipManager&);
REG_LOADER_FUNCT_TYPE(GameState);
REG_LOADER_FUNCT_TYPE(ShipManager);
REG_LOADER_FUNCT_TYPE(Ship);
REG_LOADER_FUNCT_TYPE(SkillManager);
REG_LOADER_FUNCT_TYPE(Unit);

class _GET_DLL_NAME(Serialization) : public _GET_DLL_NAME()
{
public:
    _GET_DLL_NAME(Serialization)();

    JsonSaver _GETTER(json_saver)() const;
    JsonLoader _GETTER(json_loader)() const;

    REG_GETTER_FOR_SERIALIZERS(Field, field_serializer);
    REG_GETTER_FOR_SERIALIZERS(GameState, game_state_serializer);
    REG_GETTER_FOR_SERIALIZERS(ShipManager, ship_manager_serializer);
    REG_GETTER_FOR_SERIALIZERS(Ship, ship_serializer);
    REG_GETTER_FOR_SERIALIZERS(SkillManager, skill_manager_serializer);
    REG_GETTER_FOR_SERIALIZERS(Unit, unit_serializer);

    REG_GETTER_FOR_LOADERS(Field, field_loader);
    REG_GETTER_FOR_LOADERS(GameState, game_state_loader);
    REG_GETTER_FOR_LOADERS(ShipManager, ship_manager_loader);
    REG_GETTER_FOR_LOADERS(Ship, ship_loader);
    REG_GETTER_FOR_LOADERS(SkillManager, skill_manager_loader);
    REG_GETTER_FOR_LOADERS(Unit, unit_loader);

};

} // seagame


#endif // _SERIALIZATION_DLL_H

