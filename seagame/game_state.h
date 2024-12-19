#pragma once


#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include "field.h"
#include "ship_manager.h"
#include "skill_manager.h"
#include "file.h"
#include "serialization_dll.h"

namespace seagame
{

class GameState : public Owner
{
public:
	explicit GameState(Field &&_player_field, Field &&_enemy_field,
					   ShipManager &&_player_ship_manager, ShipManager &&_enemy_ship_manager,
					   SkillManager &&_player_skill_manager);

	explicit GameState(Field &&_player_field, Field &&_enemy_field);

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


	void set_player_field(Field &&_player_field) noexcept;
	void set_enemy_field(Field &&_enemy_field) noexcept;

	void set_player_ship_manager(ShipManager &&_player_ship_manager) noexcept;
	void set_enemy_ship_manager(ShipManager &&_enemy_ship_manager) noexcept;

	void set_player_skill_manager(SkillManager &&_player_skill_manager) noexcept;

private:
	Field _player_field;
	Field _enemy_field;

	ShipManager _player_ship_manager;
	ShipManager _enemy_ship_manager;

	SkillManager _player_skill_manager;

};

} // seagame

seagame::File& operator<<(seagame::File &f, seagame::GameState &game_state);

seagame::File& operator>>(seagame::File &f, seagame::GameState &game_state);

seagame::File& operator<<(seagame::File &&f, seagame::GameState &game_state);

seagame::File& operator>>(seagame::File &&f, seagame::GameState &game_state);

#endif // _GAME_STATE_H
