#include "serialization_dll.h"


namespace seagame
{

SerializationDll::SerializationDll()
    : DLL("serialization/serialization.dll")
{    }

JsonSaver 
SerializationDll::get_json_saver() const
{ return this->get_unit<JsonSaver>("json_save"); }

JsonLoader 
SerializationDll::get_json_loader() const
{ return this->get_unit<JsonLoader>("json_load"); }

} // seagame

