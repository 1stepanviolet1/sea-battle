#pragma once


#ifndef _OUT_OF_FIELD_ERROR_H
#define _OUT_OF_FIELD_ERROR_H

#include <stdexcept>

namespace seagame
{

class OutOfFieldError : public std::invalid_argument
{
public:
    OutOfFieldError(std::string &&msg)
        : std::invalid_argument(msg)
    {    }

};

} // seagame


#endif // _OUT_OF_FIELD_ERROR_H

