#pragma once


#ifndef _FIELD_LOADER_H
#define _FIELD_LOADER_H

#include "field_size_loader.h"
#include "unit_loader.h"
#include "ship_manager.h"

namespace seagame
{

class SERIALIZATION_API _GET_LOADER_NAME(Field) 
    : public _GET_LOADER_NAME()
{
public:
    explicit _GET_LOADER_NAME(Field)(const ShipManager &_ship_manager);
    void load(const nlohmann::json &_json) override;

private:
    const ShipManager &_ship_manager;

    _GET_LOADER_NAME(FieldSize) field_size_loader;
    _GET_LOADER_NAME(Unit) unit_loader;   

};

} // seagame


#endif // _FIELD_LOADER_H

