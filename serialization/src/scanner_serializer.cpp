#include "scanner_serializer.h"


namespace seagame
{

void 
ScannerSerializer::operator()(Void *_obj)
{
    Scanner &scanner = static_cast<Scanner&>(*_obj);
    
    UnitSerializer unit_serializer;
    Unit unit = scanner.unit();
    unit_serializer.save(&unit);
    this->_json["_unit"] = unit_serializer.get();

}

} // seagame

