#pragma once


#ifndef _GAME_STATE_SERIALIZER_H
#define _GAME_STATE_SERIALIZER_H

#include "field_serializer.h"
#include "ship_manager_serializer.h"
#include "skill_manager_serializer.h"

#include "game_state.h"

namespace seagame
{

class SERIALIZATION_API _GET_SERIALIZER_NAME(GameState) 
    : public _GET_SERIALIZER_NAME()
{
private:
    _GET_SERIALIZER_NAME(Field) field_serializer;
    _GET_SERIALIZER_NAME(ShipManager) ship_manager_serializer;
    _GET_SERIALIZER_NAME(SkillManager) skill_manager_serializer;

public:
    void operator()(Void *_obj) override;

private:
    template <class T>
    T& __del_const(const T &_obj)
    { return const_cast<T&>(_obj); }

};

} // seagame


#endif // _GAME_STATE_SERIALIZER_H

