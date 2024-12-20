#pragma once


#ifndef _FILE_H
#define _FILE_H

#include <string>

#include "owner.h"

namespace seagame
{

class File : public Owner
{
public:
    File(const std::string &name);
    File(std::string &&name) noexcept;
	File();

    File(File &&other) noexcept;

    const std::string& name(const std::string &name) noexcept;
    const std::string& name() const noexcept;

private:
	std::string _name;

};

} // seagame


#endif // _FILE_H
