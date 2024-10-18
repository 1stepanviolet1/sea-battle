#include "seagame/ship_manager.h"
#include "seagame/field.h"
#include "seagame/skill_manager.h"
#include "setup_react_of_destroyed_ship.h"
#include "add_random_skill.h"
#include "extract_error.h"
#include "out_of_field_error.h"
#include "placement_error.h"

#include <iostream>

using Unit = seagame::Unit;
using SkillName = seagame::SkillName;


int main()
{
    seagame::ShipManager sm({
        seagame::Ship::Len::TWO,
        seagame::Ship::Len::FOUR
    });

    std::uint64_t i = sm.new_ship(
        seagame::Ship::Len::THREE,
        seagame::Ship::Orientation::VERTICAL
    );

    seagame::Field field(5, 5);

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

    bool scanner_is_worked = false;
    bool flag;
    std::equal_to<Unit> eq;
    for (std::size_t i = 0; i < 3; ++i)
    {
        std::shared_ptr<seagame::iSkillFactory> _f_skill;
        try
        {
            _f_skill = skill_manager.extract_skill();
        } catch (const seagame::ExtractError &err)
        {
            std::cerr << "Error: " << err.what() << std::endl;
            continue;
        }
        
        try
        {
            field.accept_skill(_f_skill->create(Unit(2, 3), 
                               [&flag, &eq, &scanner_is_worked](const Unit &_u){ 
                scanner_is_worked = true;

                !eq(Unit(), _u) 
                    ? flag = true
                    : flag = false;
            }));   
        } catch (const std::invalid_argument &err)
        {
            std::cerr << "Error: " << err.what() << std::endl;
        }
        
    }

    if (scanner_is_worked)
    {
        if (flag)
            std::cout << "Scanner found ships" << std::endl;
        else
            std::cout << "Scanner doesn't found ships" << std::endl;
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

    return 0;

}

