#include "sword_red_gem.h"

#include "engine.h"
#include "swing.h"

SwordRedGem::SwordRedGem(int damage) : Weapon{"sword_red_gem", damage + 3} {}

void SwordRedGem::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}
