#pragma once


#ifndef _GAME_H
#define _GAME_H

#include "setup_react_of_destroyed_ship.h"
#include "add_random_skill.h"
#include "extract_error.h"
#include "out_of_field_error.h"
#include "placement_error.h"
#include "game_state.h"

namespace seagame
{

class Game
{
public:
	Game();

	~Game();

private:
	GameState _state;

};

} // seagame


#endif // _GAME_H
