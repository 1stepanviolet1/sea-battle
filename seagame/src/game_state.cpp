#include "game_state.h"


namespace seagame
{

GameState::GameState(Field &&_player_field, Field &&_enemy_field,
					 ShipManager &&_player_ship_manager, ShipManager &&_enemy_ship_manager,
					 SkillManager &&_player_skill_manager)
	: _player_field(_player_field), _enemy_field(_enemy_field),
	  _player_ship_manager(_player_ship_manager), _enemy_ship_manager(_enemy_ship_manager),
	  _player_skill_manager(_player_skill_manager)
{    }

GameState::GameState(Field &&_player_field, Field &&_enemy_field)
	: GameState(Field(_player_field), Field(_enemy_field), 
				ShipManager({}), ShipManager({}),
				SkillManager())
{    }

GameState::GameState()
	: GameState(Field(10, 10),
				Field(10, 10))
{    }

GameState::GameState(const GameState& other)
	: _player_field(other._player_field),
	  _enemy_field(other._enemy_field),

	  _player_ship_manager(other._player_ship_manager),
	  _enemy_ship_manager(other._enemy_ship_manager),

	  _player_skill_manager(other._player_skill_manager)
{    }

GameState::GameState(GameState&& other) noexcept
	: _player_field(std::move(other._player_field)),
	  _enemy_field(std::move(other._enemy_field)),

	  _player_ship_manager(std::move(other._player_ship_manager)),
	  _enemy_ship_manager(std::move(other._enemy_ship_manager)),

	  _player_skill_manager(std::move(other._player_skill_manager))
{    }

GameState& 
GameState::operator=(const GameState& other)
{
	if (this != &other)
	{
		this->_player_field = other._player_field;
		this->_enemy_field = other._enemy_field;
		this->_player_ship_manager = other._player_ship_manager;
		this->_enemy_ship_manager = other._enemy_ship_manager;
		this->_player_skill_manager = other._player_skill_manager;
	}
	return *this;
}

GameState& 
GameState::operator=(GameState&& other) noexcept
{
	if (this != &other)
	{
		this->_player_field = std::move(other._player_field);
		this->_enemy_field = std::move(other._enemy_field);
		this->_player_ship_manager = std::move(other._player_ship_manager);
		this->_enemy_ship_manager = std::move(other._enemy_ship_manager);
		this->_player_skill_manager = std::move(other._player_skill_manager);
	}
	return *this;
}


Field& 
GameState::get_player_field() noexcept
{ return this->_player_field; }

Field& 
GameState::get_enemy_field() noexcept
{ return this->_enemy_field; }

ShipManager&
GameState::get_player_ship_manager() noexcept
{ return this->_player_ship_manager; }

ShipManager&
GameState::get_enemy_ship_manager() noexcept
{ return this->_enemy_ship_manager; }

SkillManager&
GameState::get_player_skill_manager() noexcept
{ return this->_player_skill_manager; }


void 
GameState::set_player_field(Field&& _player_field) noexcept
{
	this->_player_field = _player_field;
}

void 
GameState::set_enemy_field(Field&& _enemy_field) noexcept
{
	this->_enemy_field = _enemy_field;
}

void 
GameState::set_player_ship_manager(ShipManager&& _player_ship_manager) noexcept
{
	this->_player_ship_manager = _player_ship_manager;
}

void 
GameState::set_enemy_ship_manager(ShipManager&& _enemy_ship_manager) noexcept
{
	this->_enemy_ship_manager = _enemy_ship_manager;
}

void 
GameState::set_player_skill_manager(SkillManager&& _player_skill_manager) noexcept
{
	this->_player_skill_manager = _player_skill_manager;
}

} // seagame

