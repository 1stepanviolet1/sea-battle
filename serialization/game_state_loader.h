#pragma once


#ifndef _GAME_STATE_LOADER_H
#define _GAME_STATE_LOADER_H

#include "field_loader.h"
#include "ship_manager_loader.h"
#include "skill_manager_loader.h"

#include "game_state.h"

namespace seagame
{

class SERIALIZATION_API _GET_LOADER_NAME(GameState) 
    : public _GET_LOADER_NAME()
{
private:
    _GET_LOADER_NAME(Field) field_loader;
    _GET_LOADER_NAME(ShipManager) ship_manager_loader;
    _GET_LOADER_NAME(SkillManager) skill_manager_loader;

public:
    void load(const nlohmann::json &_json) override;

};

} // seagame


#endif // _GAME_STATE_LOADER_H

