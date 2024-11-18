#include "dll.h"


namespace seagame
{

DLL::DLL(const std::string &_DLLPath)
{
    this->m_module = LoadLibrary(
        _DLLPath.c_str()
    );

    if (this->m_module == NULL)
        throw std::runtime_error("Failed to load serialization.DLL");
        
}


DLL::DLL(const DLL &other)
{
    this->~DLL();
    this->m_module = other.m_module;
}

DLL::DLL(DLL &&other) noexcept
{
    this->~DLL();
    this->m_module = other.m_module;
    other.m_module = NULL;
}


DLL::~DLL()
{
    if (this->m_module != NULL) 
    {
        FreeLibrary(this->m_module);
    }
}


DLL& 
DLL::operator=(const DLL &other)
{
    if (this != &other) 
    {
        this->~DLL();
        this->m_module = other.m_module;
    }
    return *this;
}

DLL& 
DLL::operator=(DLL &&other) noexcept
{
    if (this != &other) 
    {
        this->~DLL();
        this->m_module = other.m_module;
        other.m_module = NULL;
    }
    return *this;
}


HMODULE 
DLL::get() const noexcept
{ return this->m_module; }

} // seagame

