#include "sword_rusty.h"

#include "engine.h"
#include "hit.h"

SwordRusty::SwordRusty(int damage) : Weapon{"sword_rusty", damage} {}

void SwordRusty::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}