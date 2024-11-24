#include "dll.h"


namespace seagame
{

_GET_DLL_NAME()::_GET_DLL_NAME()(const std::string &_DLLPath)
{
    this->m_module = LoadLibrary(
        _DLLPath.c_str()
    );

    if (this->m_module == NULL)
        throw std::runtime_error("Failed to load serialization.dll");
        
}


_GET_DLL_NAME()::_GET_DLL_NAME()(const _GET_DLL_NAME() &other)
{
    this->~_GET_DLL_NAME()();
    this->m_module = other.m_module;
}

_GET_DLL_NAME()::_GET_DLL_NAME()(_GET_DLL_NAME() &&other) noexcept
{
    this->~_GET_DLL_NAME()();
    this->m_module = other.m_module;
    other.m_module = NULL;
}


_GET_DLL_NAME()::~_GET_DLL_NAME()()
{
    if (this->m_module != NULL) 
    {
        FreeLibrary(this->m_module);
    }
}


_GET_DLL_NAME()& 
_GET_DLL_NAME()::operator=(const _GET_DLL_NAME() &other)
{
    if (this != &other) 
    {
        this->~_GET_DLL_NAME()();
        this->m_module = other.m_module;
    }
    return *this;
}

_GET_DLL_NAME()& 
_GET_DLL_NAME()::operator=(_GET_DLL_NAME() &&other) noexcept
{
    if (this != &other)
    {
        this->~_GET_DLL_NAME()();
        this->m_module = other.m_module;
        other.m_module = NULL;
    }
    return *this;
}


HMODULE 
_GET_DLL_NAME()::get() const noexcept
{ return this->m_module; }

} // seagame

