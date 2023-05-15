#include "staff_green.h"

#include "circle.h"
#include "engine.h"
#include "lightning.h"

StaffGreen::StaffGreen(int damage) : Weapon{"staff_green", damage + 1} {}

void StaffGreen::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Circle{sprite, direction, defender, damage});
    engine.events.add(Lightning{defender.get_position(), damage});
}
