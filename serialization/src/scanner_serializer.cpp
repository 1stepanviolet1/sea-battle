#include "scanner_serializer.h"


namespace seagame
{

void 
ScannerSerializer::operator()(Void *_obj)
{
    Scanner &scanner = static_cast<Scanner&>(*_obj);
    
    UnitSerializer unit_serializer;
    unit_serializer.save(&scanner.unit());
    this->_json["_unit"] = unit_serializer.get();

}

} // seagame

