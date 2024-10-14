#pragma once


#ifndef _SCANNER_FACTORY_H
#define _SCANNER_FACTORY_H

#include <memory>

#include "iSkill_factory.h"
#include "scanner.h"

namespace seagame
{

class ScannerFactory : public iSkillFactory
{
public:
    std::shared_ptr<iSkill> create(const Unit &_unit, 
                                   const std::function<void(const Unit&)> _funct) override;

    ~ScannerFactory() override = default;

};

} // seagame


#endif // _SCANNER_FACTORY_H

