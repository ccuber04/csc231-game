#include "staff_green.h"

#include "circle.h"
#include "engine.h"

StaffGreen::StaffGreen(int damage) : Weapon{"staff_green", damage} {}

void StaffGreen::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Circle{sprite, direction, defender, damage});
}
