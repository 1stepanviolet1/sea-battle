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
    ShipManager &player_manager = this->_state.get_player_ship_manager();
    
    std::vector<Ship::Len> ship_lens;
    for (const auto &_ship : player_manager.container())
        ship_lens.push_back(_ship.len());

    this->_state.set_enemy_ship_manager(ShipManager(ship_lens));
    Field &field = this->_state.get_enemy_field();

    for (const auto &_ship : this->_state.get_enemy_ship_manager().container())
        field.add_ship(
            const_cast<Ship&>(_ship),
            this->_rd() % field.size().m(),
            this->_rd() % field.size().n()
        );

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

} // seagame

