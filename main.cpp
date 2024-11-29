#include "game.h"
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

    std::cout << "-----" << std::endl;

    std::cout << "JSON TEST" << std::endl;

    seagame::SerializationDLL serialization;

    seagame::JsonSaver json_saver = serialization.get_json_saver();
    seagame::JsonLoader json_loader = serialization.get_json_loader();

    seagame::_GET_SERIALIZER_NAME(Unit) unit_serializer = serialization._GETTER(unit_serializer)();

    Unit unit = Unit(5, 6);
    nlohmann::json json = unit_serializer(unit);

    try
    {
        json_saver(json, "settings.json");
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    seagame::_GET_LOADER_NAME(Unit) unit_loader = serialization._GETTER(unit_loader)();
    
    nlohmann::json loaded_json;
    try
    {
        loaded_json = json_loader("settings.json");
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << "Error: " << err.what() << '\n';
    }
    std::cout << loaded_json.dump(2) << std::endl;
    
    std::cout << "-----" << std::endl;
    
    Unit _unit = *static_cast<Unit*>(unit_loader(loaded_json).get());

    std::cout << "Unit(" << _unit.x() << ", " << _unit.y() << ")" << std::endl;

    std::cout << "-----" << std::endl;

    return 0;

}

