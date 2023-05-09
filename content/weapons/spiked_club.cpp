#include "spiked_club.h"

#include "engine.h"
#include "swing.h"

SpikedClub::SpikedClub(int damage) : Weapon{"spiked_club", damage} {}

void SpikedClub::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}
