#include "spear.h"

#include "engine.h"
#include "hit.h"

Spear::Spear(int damage) : Weapon{"spear", damage} {}

void Spear::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
