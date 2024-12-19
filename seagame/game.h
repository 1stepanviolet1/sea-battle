#pragma once


#ifndef _GAME_H
#define _GAME_H

#include "extract_error.h"
#include "game_state.h"

namespace seagame
{

enum GAME_OVER_FLAG
{
	ENEMY,
	PLAYER, 
	NOBODY
};

class Game : public Owner
{
private:
	GameState _state;

	Unit _bot_attack_unit;
	std::random_device _rd;

public:
	Game();

	void user_attack(const Unit & _unit);

	SkillResultStatus user_skill(const Unit &_unit = Unit());

	void load_game();

	void save_game();

	void new_game();

	void bot_attack();
	void setup_bot();

	GAME_OVER_FLAG is_game_over() noexcept;

	GameState& state() noexcept;

	~Game() = default;

private:
	void _update_bot_attack_unit();

};

} // seagame


#endif // _GAME_H
