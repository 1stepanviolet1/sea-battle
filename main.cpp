#include "seagame/ship_manager.h"
#include "seagame/field.h"
#include "seagame/double_hit.h"
#include "seagame/rocket_attack.h"
#include "seagame//scanner.h"

#include <iostream>



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

    field.add_ship(sm[i], seagame::Unit(2, 1));
    field.add_ship(sm[0], seagame::Unit(4, 2));
    field.add_ship(sm[1], seagame::Unit(2, 5));
   
    field.shot(seagame::Unit(1, 1));

    seagame::DoubleHit _dh(2, 3);
    seagame::RocketAttack _ra;

    field.accept_skill(&_dh);

    field.accept_skill(&_ra);

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

    seagame::Scanner _sc(1, 3, [&flag](auto){
        flag = true;
    });

    field.accept_skill(&_sc);

    if (flag)
        std::cout << "Scanner found ships" << std::endl;
    else
        std::cout << "Scanner doesn't found ships" << std::endl;

    return 0;

}

