#include "skill_manager_serializer.h"


namespace seagame
{

void 
_GET_SERIALIZER_NAME(SkillManager)::operator()(Void *_obj)
{
    SkillManager &skill_manager = *static_cast<SkillManager*>(_obj);
    
    this->_json["_queue_of_skills"] = nlohmann::json::array();

    std::queue<std::shared_ptr<iSkillFactory>> skill_factories;
    
    while (!skill_manager.empty())
    {
        this->_json["_queue_of_skills"].push_back(skill_manager.front_skill());
        skill_factories.push(skill_manager.extract_skill());
    }

    while (!skill_factories.empty())
    {
        skill_manager.produce_skill(skill_factories.front()->skillname());
        skill_factories.pop();
    }

}

} // seagame

