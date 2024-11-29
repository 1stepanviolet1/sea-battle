#pragma once


#ifndef _SHIP_MANAGER_LOADER_H
#define _SHIP_MANAGER_LOADER_H

#include "ship_loader.h"
#include "ship_manager.h"

namespace seagame
{

class SERIALIZATION_API _GET_LOADER_NAME(ShipManager) 
    : public _GET_LOADER_NAME()
{
public:
    void load(const nlohmann::json &_json) override;

private:
    _GET_LOADER_NAME(Ship) ship_loader;

};

} // seagame


#endif // _SHIP_MANAGER_LOADER_H

