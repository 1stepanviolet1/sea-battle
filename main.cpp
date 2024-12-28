#include "setup_react_of_destroyed_ship.h"
#include "game.h"
#include "serialization_dll.h"
#include "placement_error.h"
#include "add_random_skill.h"
#include "serialization_dll.h"


#include <iostream>

using Unit = seagame::Unit;
using SkillName = seagame::SkillName;


int main()
{
    seagame::Game game_object;
    game_object.setup_bot();

    seagame::ShipManager &sm = game_object.state().get_player_ship_manager();
    seagame::Field &field = game_object.state().get_player_field();
    seagame::SkillManager &skill_manager = game_object.state().get_player_skill_manager();
    
    field.accept<seagame::SetupReactOfDestroyedShip>(
        std::make_shared<seagame::AddRandomSkill>(skill_manager)
    );

    std::uint64_t i;

    try
    {
        sm = seagame::ShipManager({
            seagame::Ship::Len::TWO,
            seagame::Ship::Len::FOUR
        });

        i = sm.new_ship(
            seagame::Ship::Len::THREE,
            seagame::Ship::Orientation::VERTICAL
        );
    }
    catch (const std::invalid_argument& err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        i = -1;
    }

    

    try
    {
        field = seagame::Field(5, 5);
    } catch (const std::invalid_argument& err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }


    try
    {
        if (i != -1) field.add_ship(sm[i], Unit(2, 1));
        field.add_ship(sm[0], Unit(4, 2));
        field.add_ship(sm[1], Unit(2, 5));
    } catch (const seagame::PlacementError &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    

    try
    {
        game_object.user_attack(Unit(9, 6));
        game_object.user_attack(Unit(9, 6));
    } catch (const std::invalid_argument &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }

    try
    {
        seagame::SkillResultStatus status = game_object.user_skill(Unit(3, 5));
        std::cout << "Skill result: " << status << std::endl;
    }
    catch(const seagame::ExtractError&)
    {
        std::cerr << "No skills" << std::endl;
    }

    game_object.bot_attack();
    
    std::cout << "-----" << std::endl;
    
    std::cout << sm[i].segments()[0] << ' ';
    std::cout << sm[i].segments()[1] << ' ';
    std::cout << sm[i].segments()[2] << std::endl;

    std::cout << sm[0].segments()[0] << ' ';
    std::cout << sm[0].segments()[1] << std::endl;

    std::cout << sm[1].segments()[0] << ' ';
    std::cout << sm[1].segments()[1] << ' ';
    std::cout << sm[1].segments()[2] << ' ';
    std::cout << sm[1].segments()[3] << std::endl;

    std::cout << "-----" << std::endl;

    std::cout << "skill_manager len: " << skill_manager.empty() << std::endl;

    std::cout << "SERIALIZE TEST" << std::endl;

    try
    {
        game_object.save_game();
    }
    catch(const std::exception&)
    {
        std::cerr << "bad save" << std::endl;
    }

    std::cout << "-----" << std::endl;

    std::cout << "LOAD TEST" << std::endl;

    try
    {
        game_object.load_game();
    }
    catch(const std::exception&)
    {
        std::cerr << "bad load" << std::endl;
    }

    std::cout << "-----" << std::endl;

    return 0;

}

