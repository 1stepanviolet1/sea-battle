#pragma once


#ifndef _DLL_H
#define _DLL_H

#include <Windows.h>
#include <string>
#include <stdexcept>

namespace seagame
{

class DLL
{
public:
    DLL(const std::string &_DLLPath);

    DLL(const DLL &other);
    DLL(DLL &&other) noexcept;

    virtual ~DLL();

    DLL& operator=(const DLL &other);
    DLL& operator=(DLL &&other) noexcept;

    HMODULE get() const noexcept;
    
protected:
    HMODULE m_module;

};

} // seagame


#endif // _DLL_H

