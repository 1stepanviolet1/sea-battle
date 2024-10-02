#include "../owner.h"


namespace seagame
{

void
Owner::accept(Visitor *_v)
{
    (*_v)(this);
}

Owner::~Owner() {    }

} // seagame

