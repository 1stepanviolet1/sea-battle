#include "../scanner_factory.h"

#include <string>
#include <functional>
#include <stdexcept>


namespace seagame
{

std::shared_ptr<iSkill>
ScannerFactory::create(const Unit &_unit, 
                       const std::function<void(const Unit&)> &_funct)
{
    if (std::string(_funct.target_type().name())
     == std::string(std::function<void(const Unit&)>(__plug_for_react()).target_type().name())) 
    {
        throw std::invalid_argument("bad reaction");
    }

    return std::make_shared<Scanner>(_unit, _funct);

}

} // seagame

