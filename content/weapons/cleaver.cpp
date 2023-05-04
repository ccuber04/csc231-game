#include "cleaver.h"

#include "engine.h"
#include "hit.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
