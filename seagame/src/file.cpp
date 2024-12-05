#include "file.h"


namespace seagame
{

File::File(const std::string &name)
    : _name(name)
{

}

File::File(std::string &&name) noexcept
    : _name(name)
{
    
}

File::File()
{
    
}


const std::string&
File::name(const std::string &name) noexcept
{
    this->_name = name;
    return this->_name;
}

const std::string& 
File::name() const noexcept
{ return this->_name; }

} // seagame

