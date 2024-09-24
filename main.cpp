#include "seagame/ship_manager.h"
#include "seagame/field.h"

#include <iostream>


int main()
{
    seagame::ShipManager sm({
        seagame::Ship::Len::ONE,
        seagame::Ship::Len::TWO,
        seagame::Ship::Len::THREE,
        seagame::Ship::Len::FOUR
    });

    seagame::Field field(3, 3);

    field.add_ship(sm[2], seagame::Unit(1, 1));

    std::cout << std::equal_to<seagame::Unit>()(seagame::Unit(1, 3), seagame::Unit(1, 3)) << std::endl;

    return 0;
    
}
