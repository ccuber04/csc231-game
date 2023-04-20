#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;

    Tile& tile = engine.dungeon.tiles(position);

    for (auto& [pos, door] : engine.dungeon.doors) {
        door.open();
    }

    actor->change_direction(direction);

    if (tile.is_wall()) {
        return failure();
    }
    if (tile.is_door()) {
        return failure();
        // return alternative(OpenDoor(position));
    }
    // fail if actor is on tile
    actor->move_to(position);
    return success();
}