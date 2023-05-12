#include "die.h"

#include "engine.h"

Die::Die(Actor& actor) : actor{actor} {}

void Die::execute(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor.get_position());
    if (!tile.weapon) {
        // Drop{};
    }
    actor.alive = false;
    engine.dungeon.remove_actor(actor.get_position());
}