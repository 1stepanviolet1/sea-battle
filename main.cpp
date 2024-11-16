#include "game.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <Windows.h>

using Unit = seagame::Unit;
using SkillName = seagame::SkillName;

typedef void(*JsonSaver)(const nlohmann::json&, const std::string&);
typedef nlohmann::json(*JsonLoader)(const std::string&);


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

    HMODULE serialization = LoadLibrary(TEXT("serialization/serialization.dll"));
    if (serialization == NULL) {
        std::cerr << "Failed to load serialization.dll" << std::endl;
        return 1;
    }

    JsonSaver json_saver = (JsonSaver)GetProcAddress(serialization, "json_save");
    if (json_saver == NULL) {
        std::cerr << "Could not find function json_save" << std::endl;
        FreeLibrary(serialization);
        return 1;
    }

    JsonLoader json_loader = (JsonLoader)GetProcAddress(serialization, "json_load");
    if (json_loader == NULL) {
        std::cerr << "Could not find function json_load." << std::endl;
        FreeLibrary(serialization);
        return 1;
    }

    nlohmann::json json = nlohmann::json::array();

    json.push_back(nlohmann::json({
        {"test1", 123},
        {"test2", "hello"},
        {"test3", true}
    }));

    json_saver(json, "settings.json");

    std::cout << "-----" << std::endl;
    
    nlohmann::json loaded_json = json_loader("settings.json");
    std::cout << loaded_json.dump(2) << std::endl;

    std::cout << "-----" << std::endl;

    return 0;

}

