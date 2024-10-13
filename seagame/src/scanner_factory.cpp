#include "../scanner_factory.h"


namespace seagame
{

std::shared_ptr<iSkill>
ScannerFactory::operator()(const Unit &_unit, 
                           const std::function<void(const Unit&)> _funct)
{ return std::make_shared<Scanner>(_unit, _funct); }

} // seagame

