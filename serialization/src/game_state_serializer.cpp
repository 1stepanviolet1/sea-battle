#include "game_state_serializer.h"


namespace seagame
{

void 
_GET_SERIALIZER_NAME(GameState)::operator()(Void *_obj)
{
    GameState &game_state = static_cast<GameState&>(*_obj);

    this->field_serializer.save(
        &this->__del_const(game_state.get_player_field())
    );
    this->_json["_player_field"] = this->field_serializer.get(); // save the player field

    this->field_serializer.save(
        &this->__del_const(game_state.get_enemy_field())
    );
    this->_json["_enemy_field"] = this->field_serializer.get(); // save the enemy field;

    this->ship_manager_serializer.save(
        &this->__del_const(game_state.get_player_ship_manager())
    );
    this->_json["_player_ship_manager"] = this->ship_manager_serializer.get(); // save the player ship manager

    this->ship_manager_serializer.save(
        &this->__del_const(game_state.get_enemy_ship_manager())
    );
    this->_json["_enemy_ship_manager"] = this->ship_manager_serializer.get(); // save the enemy ship manager

    this->skill_manager_serializer.save(
        &this->__del_const(game_state.get_player_skill_manager())
    );
    this->_json["_player_skill_manager"] = this->skill_manager_serializer.get(); // save the player skill manager

}

} // seagame

