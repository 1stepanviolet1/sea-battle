#include "game.h"


namespace seagame
{

Game::Game()
{    }


void 
Game::user_attack(const Unit & _unit)
{
    this->_state.get_enemy_field().shot(_unit);
    // maybe throw an std::invalid_argument
}

void 
Game::bot_attack()
{
    Field &field = this->_state.get_player_field();

    while (true)
    {
        try
        {
            this->_update_bot_attack_unit();
            field.shot(_bot_attack_unit);
        }
        catch(const std::invalid_argument&)
        {
            continue;
        }

        break;

    }

}

void 
Game::_update_bot_attack_unit()
{
    std::equal_to<Unit> eq_unit;
    if (eq_unit(_bot_attack_unit, Unit()))
    {
        _bot_attack_unit = Unit(1, 1);
        return;
    }

    Field &field = this->_state.get_player_field();

    if (field.size().m() <= _bot_attack_unit.x())
    {
        _bot_attack_unit = Unit(
            1,
            _bot_attack_unit.y() + 1
        );
        return;
    }

    if (field.size().n() <= _bot_attack_unit.y())
    {
        _bot_attack_unit = Unit(
            _bot_attack_unit.x(),
            1
        );
        return;
    }

    _bot_attack_unit = Unit(
        _bot_attack_unit.x() + 1, 
        _bot_attack_unit.y()
    );

}

SkillResultStatus 
Game::user_skill(const Unit &_unit)
{
    SkillManager &skill_manager = this->_state.get_player_skill_manager();
    Field &field = this->_state.get_enemy_field();

    std::shared_ptr<seagame::iSkillFactory> _f_skill;
    std::shared_ptr<seagame::iSkill> _skill;

    _f_skill = skill_manager.extract_skill();
    // maybe throw an std::ExtractError

    _skill = _f_skill->create(_unit);
    
    try
    {
        field.accept_skill(_skill);
    } catch (const std::invalid_argument &)
    {
        return SkillResultStatus::NONE;
    }

    return _skill->result()->get();
    
}

void 
Game::load_game()
{
    File("settings.json") >> this->_state;
    // maybe throw an std::invalid_argument

}

void 
Game::save_game()
{
    File("settings.json") << this->_state;

}

void 
Game::new_game()
{
    this->_state = GameState();
    // TODO:
}

void 
Game::setup_bot()
{
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::FOUR, Ship::Orientation::VERTICAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::THREE, Ship::Orientation::HORIZONTAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::THREE, Ship::Orientation::VERTICAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::TWO, Ship::Orientation::VERTICAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::TWO, Ship::Orientation::VERTICAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::TWO, Ship::Orientation::HORIZONTAL);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::ONE);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::ONE);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::ONE);
    this->_state.get_enemy_ship_manager().new_ship(Ship::Len::ONE);

    this->_state.get_enemy_field().size(Field::Size(10, 10));

    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[0], Unit(3, 4));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[1], Unit(5, 2));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[2], Unit(9, 2));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[3], Unit(6, 5));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[4], Unit(9, 8));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[5], Unit(6, 9));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[6], Unit(2, 1));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[7], Unit(2, 9));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[8], Unit(4, 10));
    this->_state.get_enemy_field().add_ship(this->_state.get_enemy_ship_manager()[9], Unit(9, 6));

}

GAME_OVER_FLAG 
Game::is_game_over() noexcept
{
    ShipManager &player_ship_manager = this->_state.get_player_ship_manager();
    if (player_ship_manager.all_destroyed())
        return GAME_OVER_FLAG::ENEMY;
    
    ShipManager &enemy_ship_manager = this->_state.get_enemy_ship_manager();
    if (player_ship_manager.all_destroyed())
        return GAME_OVER_FLAG::PLAYER;

    return GAME_OVER_FLAG::NOBODY;

}

GameState& 
Game::state() noexcept
{ return this->_state; }

void 
Game::set_state(GameState & _state) noexcept
{
    this->_state = _state;

}

} // seagame

seagame::File& operator<<(seagame::File &f, seagame::GameState &game_state)
{
	seagame::SerializationDLL dll;

	seagame::JsonSaver saver = dll.get_json_saver();
	seagame::GameStateSerializer_t serializer = dll.get_game_state_serializer();

	saver(serializer(game_state), f.name());

	return f;

}

seagame::File& operator>>(seagame::File &f, seagame::GameState &game_state)
{
	seagame::SerializationDLL dll;

	seagame::JsonLoader loader = dll.get_json_loader();
	seagame::GameStateLoader_t reader = dll.get_game_state_loader();

	game_state = std::move(*static_cast<seagame::GameState*>(
		reader(loader(f.name())).get()
	));

	return f;

}

seagame::File& operator<<(seagame::File &&f, seagame::GameState &game_state)
{
	seagame::File file(std::move(f.name()));
	file << game_state;
	return f;

}

seagame::File& operator>>(seagame::File &&f, seagame::GameState &game_state)
{
	seagame::File file(std::move(f.name()));
	file >> game_state;
	return f;
	
}

