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

} // seagame

