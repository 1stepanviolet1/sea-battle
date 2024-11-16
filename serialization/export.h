#pragma once


#ifndef _EXPORT_H
#define _EXPORT_H

#include "dll_def.h"

#include <functional>

#include "void.h"

using Factory = std::function<seagame::Void*(void)>;
using Сleaner = std::function<void(seagame::Void*)>;




#endif // _EXPORT_H

