#include "move.h"

#include <iostream>

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "opendoor.h"
#include "rest.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;

    Tile& tile = engine.dungeon.tiles(position);

    actor->change_direction(direction);

    if (tile.is_wall()) {
        // return failure();
        return alternative(Rest{});
    }

    if (tile.actor) {
        return alternative(Attack(*tile.actor));
    }

    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (!door.is_open()) {
            return alternative(OpenDoor{position});
        }
    }

    actor->move_to(position);
    return success();
}