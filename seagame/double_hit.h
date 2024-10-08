#pragma once


#ifndef _DOUBLE_HIT_H
#define _DOUBLE_HIT_H

#include <type_traits>

#include "unit.h"
#include "field.h"

namespace seagame
{

class DoubleHit : public iSkill
{
public:
    DoubleHit();

    void operator()(void *_obj) override;
    
    template <class ...Args_T>
    void install_input_data(Args_T ..._args) override
    {
        bool unit_installed = false;

        auto processing = [&unit_installed, this](auto _arg)
        {
            if (unit_installed)
                throw std::invalid_argument("too many arguments");
            
            if constexpr (!std::is_same_v<decltype(_arg), Unit>)
                throw std::invalid_argument("input data must be Unit");

            this->_unit = _arg;
            unit_installed = true;
        }

        (processing(_args), ...);

    }

    ~DoubleHit() override = default;

private:
    Unit _unit;
};

} // seagame


#endif // _DOUBLE_HIT_H

