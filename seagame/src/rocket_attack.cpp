#include "../rocket_attack.h"


namespace seagame
{

RocketAttack::RocketAttack(std::shared_ptr<_last_skill_result> _last_res)
    : Skill(_last_res)
{    }

RocketAttack::RocketAttack()
    : RocketAttack(std::make_shared<_last_skill_result>())
{    }


void
RocketAttack::operator()(Void *_obj)
{
    Field &_fd = *static_cast<Field*>(_obj);

    Ship &_ship = _fd._deployed_ships.at(
        this->__get_random_unit_of_ship(_fd)
    );

    _ship.hit(
        this->__get_random_index_of_segments(_ship)
    );

    if (_ship.is_destroyed())
        _fd._react_of_destroyed_ship->exec();

    this->_last_res->set(SkillResultStatus::SUCCESS);

}


Unit
RocketAttack::__get_random_unit_of_ship(const Field &_fd) noexcept
{
    std::vector<Unit> _valid_ships_units;

    for (const auto &_unit_ship : _fd._deployed_ships)
    {
        if (!_unit_ship.second.get().is_destroyed())
            _valid_ships_units.push_back(_unit_ship.first);
    }

    return _valid_ships_units[this->rd() % _valid_ships_units.size()];

}

std::uint8_t 
RocketAttack::__get_random_index_of_segments(const Ship &_ship) noexcept
{
    std::vector<std::uint8_t> _valid_ship_segments;

    for (std::uint8_t i = 0; i < _ship.segments().size(); ++i)
    {
        if (_ship.segments()[i] != Ship::Integrity::DESTROYED)
            _valid_ship_segments.push_back(i);
    }

    return _valid_ship_segments[this->rd() % _valid_ship_segments.size()];
}


SkillName
RocketAttack::skillname() const noexcept
{ return SkillName::ROCKETATTACK; }

} // seagame

