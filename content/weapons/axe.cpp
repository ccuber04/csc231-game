#include "axe.h"

#include "engine.h"
#include "swing.h"

Axe::Axe(int damage) : Weapon{"axe", damage + 1} {}

void Axe::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}
