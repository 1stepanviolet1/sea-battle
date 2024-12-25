#include "game_state.h"


namespace seagame
{

GameState::GameState(const Field &_player_field, const Field &_enemy_field,
					 const ShipManager &_player_ship_manager, const ShipManager &_enemy_ship_manager,
					 const SkillManager &_player_skill_manager)
	: _player_field(_player_field), _enemy_field(_enemy_field),
	  _player_ship_manager(_player_ship_manager), _enemy_ship_manager(_enemy_ship_manager),
	  _player_skill_manager(_player_skill_manager)
{    }

GameState::GameState(const Field &_player_field, const Field &_enemy_field)
	: GameState(_player_field, _enemy_field, 
				{}, {},
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
GameState::set_player_field(const Field& _player_field) noexcept
{
	this->_player_field = _player_field;
}

void 
GameState::set_enemy_field(const Field& _enemy_field) noexcept
{
	this->_enemy_field = _enemy_field;
}

void 
GameState::set_player_ship_manager(const ShipManager& _player_ship_manager) noexcept
{
	this->_player_ship_manager = _player_ship_manager;
}

void 
GameState::set_enemy_ship_manager(const ShipManager& _enemy_ship_manager) noexcept
{
	this->_enemy_ship_manager = _enemy_ship_manager;
}

void 
GameState::set_player_skill_manager(const SkillManager& _player_skill_manager) noexcept
{
	this->_player_skill_manager = _player_skill_manager;
}

} // seagame

