#include "export.h"


namespace seagame
{

extern "C" SERIALIZATION_API void
json_save(const nlohmann::json &_json, const std::string &_filename)
{
    Json obj(_filename);
    obj.save(_json);

}

extern "C" SERIALIZATION_API nlohmann::json
json_load(const std::string &_filename)
{
    Json obj(_filename);
    return obj.load();

}


extern "C" SERIALIZATION_API nlohmann::json
serialize_field(Field &_field)
{
    _GET_SERIALIZER_NAME(Field) serializer;
    serializer.save(&_field);
    return serializer.get();

}

extern "C" SERIALIZATION_API nlohmann::json
serialize_game_state(GameState &_game_state)
{
    _GET_SERIALIZER_NAME(GameState) serializer;
    serializer.save(&_game_state);
    return serializer.get();

}

extern "C" SERIALIZATION_API nlohmann::json
serialize_ship_manager(ShipManager &_ship_manager)
{
    _GET_SERIALIZER_NAME(ShipManager) serializer;
    serializer.save(&_ship_manager);
    return serializer.get();

}

extern "C" SERIALIZATION_API nlohmann::json
serialize_ship(Ship &_ship)
{
    _GET_SERIALIZER_NAME(Ship) serializer;
    serializer.save(&_ship);
    return serializer.get();

}

extern "C" SERIALIZATION_API nlohmann::json
serialize_skill_manager(SkillManager &_skill_manager)
{
    _GET_SERIALIZER_NAME(SkillManager) serializer;
    serializer.save(&_skill_manager);
    return serializer.get();

}

extern "C" SERIALIZATION_API nlohmann::json
serialize_unit(Unit &_unit)
{
    _GET_SERIALIZER_NAME(Unit) serializer;
    serializer.save(&_unit);
    return serializer.get();

}

} // seagame

