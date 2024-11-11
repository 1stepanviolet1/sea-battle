#pragma once


#ifndef _SCANNER_FACTORY_H
#define _SCANNER_FACTORY_H

#include <memory>

#include "skill_factory.h"
#include "scanner.h"

namespace seagame
{

class ScannerFactory : public SkillFactory
{
public:
    ScannerFactory(_last_skill_result& _last_res);

    std::shared_ptr<iSkill> create(const Unit &_unit, 
                                   const std::function<void(const Unit&)> &_funct) override;

    SkillName skillname() const noexcept override;

    ~ScannerFactory() override = default;

};

} // seagame


#endif // _SCANNER_FACTORY_H

