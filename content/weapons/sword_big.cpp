#include "sword_big.h"

#include "engine.h"
#include "hit.h"

SwordBig::SwordBig(int damage) : Weapon{"sword_big", damage} {}

void SwordBig::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
