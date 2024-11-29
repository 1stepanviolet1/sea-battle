#include "game_state_loader.h"


namespace seagame
{

void
_GET_LOADER_NAME(GameState)::load(const nlohmann::json &_json)
{
    if (!_json.contains("_player_field") ||
        !_json.contains("_enemy_field") ||
        !_json.contains("_player_ship_manager") ||
        !_json.contains("_enemy_ship_manager") ||
        !_json.contains("_player_skill_manager"))
    {
        throw std::invalid_argument("Invalid json for game state");
    }

    GameState game_state;

    this->field_loader.load(_json["_player_field"]);
    game_state.set_player_field(
        Field(*static_cast<Field*>(this->field_loader.get().get()))
    );

    this->field_loader.load(_json["_enemy_field"]);
    game_state.set_enemy_field(
        Field(*static_cast<Field*>(this->field_loader.get().get()))
    );


    this->ship_manager_loader.load(_json["_player_ship_manager"]);
    game_state.set_player_ship_manager(
        ShipManager(*static_cast<ShipManager*>(this->ship_manager_loader.get().get()))
    );

    this->ship_manager_loader.load(_json["_enemy_ship_manager"]);
    game_state.set_enemy_ship_manager(
        ShipManager(*static_cast<ShipManager*>(this->ship_manager_loader.get().get()))
    );


    this->skill_manager_loader.load(_json["_player_skill_manager"]);
    game_state.set_player_skill_manager(
        SkillManager(*static_cast<SkillManager*>(this->skill_manager_loader.get().get()))
    );


    this->_obj = std::make_shared<GameState>(std::move(game_state));

}

} // seagame

