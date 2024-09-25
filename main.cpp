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
    
    std::uint64_t i = sm.new_ship(
        seagame::Ship::Len::THREE,
        seagame::Ship::Orientation::VERTICAL
    );

    seagame::Field field(4, 4);

    field.add_ship(sm[i], seagame::Unit(2, 1));

    field.shot(2, 3);

    std::cout << sm[i].segments()[0] << std::endl;
    std::cout << sm[i].segments()[1] << std::endl;
    std::cout << sm[i].segments()[2] << std::endl;
    
    return 0;
    
}
