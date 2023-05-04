#include "spiked_club.h"

#include "engine.h"
#include "hit.h"

SpikedClub::SpikedClub(int damage) : Weapon{"spiked_club", damage} {}

void SpikedClub::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
