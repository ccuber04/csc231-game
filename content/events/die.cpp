#include "die.h"

#include <cmath>
#include <iostream>

#include "dropevt.h"
#include "engine.h"
Die::Die(Actor& actor) : actor{actor} {}

void Die::execute(Engine& engine) {
    // drop actor's weapon on tile
    engine.events.add(DropEvt{actor});

    // remove actor from game
    actor.alive = false;
    engine.dungeon.remove_actor(actor.get_position());
}