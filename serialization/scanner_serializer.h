#pragma once


#ifndef _SCANNER_SERIALIZER_H
#define _SCANNER_SERIALIZER_H

#include "unit_serializer.h"
#include "scanner.h"

namespace seagame
{

class SERIALIZATION_API ScannerSerializer : public Serializer
{
public:
    void operator()(Void *_obj) override;

private:
    UnitSerializer unit_serializer;

};

} // seagame


#endif // _SCANNER_SERIALIZER_H

