#include "seagame/ship_manager.h"
#include "seagame/field.h"
#include "seagame/skill_production.h"

#include <iostream>

using Unit = seagame::Unit;

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

    field.add_ship(sm[i], Unit(2, 1));
    field.add_ship(sm[0], Unit(4, 2));
    field.add_ship(sm[1], Unit(2, 5));
   
    field.shot(Unit(1, 1));

    seagame::SkillProduction sp;

    auto _dh = sp.get_factory(seagame::SkillName::DOUBLEHIT);
    auto _ra = sp.get_factory(seagame::SkillName::ROCKETATTACK);

    field.accept_skill(_dh->create(Unit(2, 3)));

    field.accept_skill(_ra->create());

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

    bool flag = false;

    auto _sc = sp.get_factory(seagame::SkillName::SCANNER);

    field.accept_skill(_sc->create(Unit(1, 3), 
                           [&flag](auto){
                        flag = true; 
                    }));

    if (flag)
        std::cout << "Scanner found ships" << std::endl;
    else
        std::cout << "Scanner doesn't found ships" << std::endl;

    return 0;

}

