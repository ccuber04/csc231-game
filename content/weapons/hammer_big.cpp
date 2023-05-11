#include "hammer_big.h"

#include "engine.h"
#include "swing.h"

HammerBig::HammerBig(int damage) : Weapon{"hammer_big", damage + 4} {}

void HammerBig::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}