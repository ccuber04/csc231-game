#include "sword_big.h"

#include "engine.h"
#include "swing.h"

SwordBig::SwordBig(int damage) : Weapon{"sword_big", damage + 4} {}

void SwordBig::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}
