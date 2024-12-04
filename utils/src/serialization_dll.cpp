#include "serialization_dll.h"


namespace seagame
{

_GET_DLL_NAME(Serialization)::_GET_DLL_NAME(Serialization)()
    : DLL("serialization/serialization.dll")
{    }

JsonSaver 
_GET_DLL_NAME(Serialization)::_GETTER(json_saver)() const
{ return this->get_unit<JsonSaver>("json_save"); }

JsonLoader 
_GET_DLL_NAME(Serialization)::_GETTER(json_loader)() const
{ return this->get_unit<JsonLoader>("json_load"); }


_GET_SERIALIZER_NAME(Field)
_GET_DLL_NAME(Serialization)::_GETTER(field_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(Field)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(field)
); }

_GET_SERIALIZER_NAME(GameState)
_GET_DLL_NAME(Serialization)::_GETTER(game_state_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(GameState)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(game_state)
); }

_GET_SERIALIZER_NAME(ShipManager)
_GET_DLL_NAME(Serialization)::_GETTER(ship_manager_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(ShipManager)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(ship_manager)
); }

_GET_SERIALIZER_NAME(Ship)
_GET_DLL_NAME(Serialization)::_GETTER(ship_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(Ship)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(ship)
); }

_GET_SERIALIZER_NAME(SkillManager)
_GET_DLL_NAME(Serialization)::_GETTER(skill_manager_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(SkillManager)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(skill_manager)
); }

_GET_SERIALIZER_NAME(Unit)
_GET_DLL_NAME(Serialization)::_GETTER(unit_serializer)() const
{ return this->get_unit<_GET_SERIALIZER_NAME(Unit)>(
    GET_NAME_OF_FUNCT_FROM_SERIALIZERS(unit)
); }


_GET_LOADER_NAME(Field)
_GET_DLL_NAME(Serialization)::_GETTER(field_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(Field)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(field)
); }

_GET_LOADER_NAME(GameState)
_GET_DLL_NAME(Serialization)::_GETTER(game_state_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(GameState)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(game_state)
); }

_GET_LOADER_NAME(ShipManager)
_GET_DLL_NAME(Serialization)::_GETTER(ship_manager_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(ShipManager)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(ship_manager)
); }

_GET_LOADER_NAME(Ship)
_GET_DLL_NAME(Serialization)::_GETTER(ship_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(Ship)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(ship)
); }

_GET_LOADER_NAME(SkillManager)
_GET_DLL_NAME(Serialization)::_GETTER(skill_manager_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(SkillManager)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(ship_manager)
); }

_GET_LOADER_NAME(Unit)
_GET_DLL_NAME(Serialization)::_GETTER(unit_loader)() const
{ return this->get_unit<_GET_LOADER_NAME(Unit)>(
    GET_NAME_OF_FUNCT_FROM_LOADERS(unit)
); }

} // seagame

