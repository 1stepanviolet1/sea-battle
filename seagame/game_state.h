#pragma once


#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include "field.h"
#include "ship_manager.h"
#include "skill_manager.h"

namespace seagame
{

class GameState : public Owner
{
public:
	explicit GameState(const Field &_player_field, const Field &_enemy_field,
					   const ShipManager &_player_ship_manager, const ShipManager &_enemy_ship_manager,
					   const SkillManager &_player_skill_manager);

	explicit GameState(const Field &_player_field, const Field &_enemy_field);

	GameState();

	GameState(const GameState &other);
	GameState(GameState &&other) noexcept;

	~GameState() = default;

	GameState& operator=(const GameState& other);
	GameState& operator=(GameState&& other) noexcept;

	Field& get_player_field() noexcept;
	Field& get_enemy_field() noexcept;

	ShipManager& get_player_ship_manager() noexcept;
	ShipManager& get_enemy_ship_manager() noexcept;

	SkillManager& get_player_skill_manager() noexcept;


	void set_player_field(const Field &_player_field) noexcept;
	void set_enemy_field(const Field &_enemy_field) noexcept;

	void set_player_ship_manager(const ShipManager &_player_ship_manager) noexcept;
	void set_enemy_ship_manager(const ShipManager &_enemy_ship_manager) noexcept;

	void set_player_skill_manager(const SkillManager &_player_skill_manager) noexcept;

private:
	Field _player_field;
	Field _enemy_field;

	ShipManager _player_ship_manager;
	ShipManager _enemy_ship_manager;

	SkillManager _player_skill_manager;

};

} // seagame



#endif // _GAME_STATE_H
