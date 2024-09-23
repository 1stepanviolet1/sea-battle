#include "seagame/field.h"
#include "seagame/ship_manager.h"


int main()
{
    // Example usage
    seagame::ShipManager sm({
        seagame::Ship::Len::FOUR,
        seagame::Ship::Len::THREE,
        seagame::Ship::Len::TWO,
        seagame::Ship::Len::ONE
    });

    return 0;
    
}