#include "spear.h"

#include "engine.h"
#include "thrust.h"
#include "vec.h"

Spear::Spear(int damage) : Weapon{"spear", damage + 1} {}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Thrust{sprite, direction, defender, damage});
}
