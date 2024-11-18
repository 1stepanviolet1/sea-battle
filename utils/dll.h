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

    template <class _Func_T>
    _Func_T get_unit(const std::string &_unitname) const
    {
        _Func_T _unit = (_Func_T)GetProcAddress(this->m_module, _unitname.c_str());

        if (_unit == NULL)
            return nullptr;

        return _unit;

    }
    
protected:
    HMODULE m_module;

};

} // seagame


#endif // _DLL_H

