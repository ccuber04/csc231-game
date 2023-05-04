#include "hammer_big.h"

#include "engine.h"
#include "hit.h"

HammerBig::HammerBig(int damage) : Weapon{"hammer_big", damage} {}

void HammerBig::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}