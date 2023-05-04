#include "sword_red_gem.h"

#include "engine.h"
#include "hit.h"

SwordRedGem::SwordRedGem(int damage) : Weapon{"sword_red_gem", damage} {}

void SwordRedGem::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
