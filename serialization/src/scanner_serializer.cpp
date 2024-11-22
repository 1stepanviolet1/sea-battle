#include "scanner_serializer.h"


namespace seagame
{

void 
ScannerSerializer::operator()(Void *_obj)
{
    Scanner &scanner = static_cast<Scanner&>(*_obj);
    
    Unit unit = scanner.unit();
    this->unit_serializer.save(&unit);
    this->_json["_unit"] = this->unit_serializer.get();

}

} // seagame

