#include "sword_rusty.h"

#include "engine.h"
#include "swing.h"

SwordRusty::SwordRusty(int damage) : Weapon{"sword_rusty", damage + 1} {}

void SwordRusty::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}