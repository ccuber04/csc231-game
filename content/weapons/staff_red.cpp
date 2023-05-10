#include "staff_red.h"

#include "circle.h"
#include "engine.h"
#include "lightning.h"

StaffRed::StaffRed(int damage) : Weapon{"staff_red", damage} {}

void StaffRed::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Circle{sprite, direction, defender, damage});
    engine.events.add(Lightning{defender.get_position(), damage});
}
