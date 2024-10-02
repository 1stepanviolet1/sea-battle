#include "../owner.h"


namespace seagame
{

void
accept(Visitor *_v)
{
    (*_v)(this);
}

Owner::~Owner() {    }

} // seagame

