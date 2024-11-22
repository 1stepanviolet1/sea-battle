#include "game_state_serializer.h"


namespace seagame
{

void 
GameStateSerializer::operator()(Void *_obj)
{
    GameState &game_state = static_cast<GameState&>(*_obj);
    
    FieldSerializer field_serializer;

    field_serializer.save(
        &this->__del_const(game_state.get_player_field())
    );
    this->_json["_player_field"] = field_serializer.get(); // save the player field

    field_serializer.save(
        &this->__del_const(game_state.get_enemy_field())
    );
    this->_json["_enemy_field"] = field_serializer.get(); // save the enemy field

    ShipManagerSerializer ship_manager_serializer;

    ship_manager_serializer.save(
        &this->__del_const(game_state.get_player_ship_manager())
    );
    this->_json["_player_ship_manager"] = ship_manager_serializer.get(); // save the player ship manager

    ship_manager_serializer.save(
        &this->__del_const(game_state.get_enemy_ship_manager())
    );
    this->_json["_enemy_ship_manager"] = ship_manager_serializer.get(); // save the enemy ship manager

    SkillManagerSerializer skill_manager_serializer;

    skill_manager_serializer.save(
        &this->__del_const(game_state.get_player_skill_manager())
    );
    this->_json["_player_skill_manager"] = skill_manager_serializer.get(); // save the player skill manager

}

} // seagame

