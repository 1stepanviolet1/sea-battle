#include "skill_manager_loader.h"


namespace seagame
{

void
_GET_LOADER_NAME(SkillManager)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_queue_of_skills"))
    {
        throw std::invalid_argument("Invalid json for skill manager");
    }

    SkillManager skill_manager;

    for (const auto &skill : _json["_queue_of_skills"])
        skill_manager.produce_skill(skill);

    this->_obj = std::make_shared<SkillManager>(std::move(skill_manager));

}

} // seagame

