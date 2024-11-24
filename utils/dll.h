#pragma once


#ifndef _DLL_H
#define _DLL_H

#include <Windows.h>
#include <string>
#include <stdexcept>

#define _GET_DLL_NAME(_DLL) _DLL##DLL
#define _GETTER(_NAME) get_##_NAME

namespace seagame
{

class _GET_DLL_NAME()
{
public:
    _GET_DLL_NAME()(const std::string &_DLLPath);

    _GET_DLL_NAME()(const _GET_DLL_NAME() &other);
    _GET_DLL_NAME()(_GET_DLL_NAME() &&other) noexcept;

    virtual ~_GET_DLL_NAME()();

    _GET_DLL_NAME()& operator=(const _GET_DLL_NAME() &other);
    _GET_DLL_NAME()& operator=(_GET_DLL_NAME() &&other) noexcept;

    HMODULE get() const noexcept;

    template <class _Func_T>
    _Func_T _GETTER(unit)(const std::string &_unitname) const
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

