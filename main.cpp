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
    seagame::ShipManager sm;

    try
    {
        sm = seagame::ShipManager({
            seagame::Ship::Len::TWO,
            seagame::Ship::Len::FOUR
        });
    }
    catch (const std::invalid_argument& err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }


    std::uint64_t i = sm.new_ship(
        seagame::Ship::Len::THREE,
        seagame::Ship::Orientation::VERTICAL
    );


    seagame::Field field(1, 1);

    try
    {
        field = seagame::Field(5, 5);
    } catch (const std::invalid_argument& err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }


    try
    {
        field.add_ship(sm[i], Unit(2, 1));
        field.add_ship(sm[0], Unit(4, 2));
        field.add_ship(sm[1], Unit(2, 5));
    } catch (const seagame::PlacementError &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    

    try
    {
        field.shot(Unit(1, 1));
    } catch (const std::invalid_argument &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }

    
    seagame::SkillManager skill_manager;
    
    field.accept<seagame::SetupReactOfDestroyedShip>(
        std::make_shared<seagame::AddRandomSkill>(skill_manager)
    );

    std::shared_ptr<seagame::iSkillFactory> _f_skill;
    std::shared_ptr<seagame::iSkill> _skill;
    for (std::size_t i = 0; i < 3; ++i)
    {
        try
        {
            _f_skill = skill_manager.extract_skill();
        } catch (const seagame::ExtractError &err)
        {
            std::cerr << "Error: " << err.what() << std::endl;
            continue;
        }

        _skill = _f_skill->create(Unit(2, 3));
        
        try
        {
            field.accept_skill(_skill);
        } catch (const std::invalid_argument &err)
        {
            std::cerr << "Error: " << err.what() << std::endl;
        }

        std::cout << _skill->result()->get() << std::endl;
        
    }

    skill_manager.produce_skill(SkillName::DOUBLEHIT);
    skill_manager.produce_skill(SkillName::DOUBLEHIT);

    try
    {
        field.accept_skill(skill_manager.extract_skill()->create(Unit(4, 2)));
        field.accept_skill(skill_manager.extract_skill()->create(Unit(5, 2)));
    
    } catch (const std::invalid_argument &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    } catch (const seagame::ExtractError &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    
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

    std::cout << skill_manager.empty() << std::endl;

    std::cout << "GAME OBJECT" << std::endl;

    seagame::Game game_object;
    game_object.state().set_player_ship_manager(seagame::ShipManager(sm));
    game_object.state().set_player_field(seagame::Field(field));
    game_object.state().set_player_skill_manager(seagame::SkillManager(skill_manager));
    game_object.setup_bot();

    std::cout << "SERIALIZE TEST" << std::endl;

    game_object.save_game();

    std::cout << "-----" << std::endl;

    std::cout << "LOAD TEST" << std::endl;

    game_object.load_game();

    std::cout << "-----" << std::endl;

    return 0;

}

