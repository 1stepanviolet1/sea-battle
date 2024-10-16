#pragma once


#ifndef _EXTRACT_ERROR_H
#define _EXTRACT_ERROR_H

#include <stdexcept>

namespace seagame
{

class ExtractError : public std::runtime_error
{
public:
    ExtractError(std::string &&msg)
        : std::runtime_error(msg)
    {    }

};

} // seagame


#endif // _EXTRACT_ERROR_H

