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

    seagame::DoubleHit _dh;
    seagame::RocketAttack _ra;

    _dh.install_data(seagame::Unit(2, 3));
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

    seagame::Scanner _s(3, 4);

    field.accept_skill(&_s);

    for (const auto &_unit : _s.result())
        std::cout << '(' << _unit.x() << ", " << _unit.y() << ')' << std::endl;

    return 0;

}

