#include "drop.h"

#include <iostream>

#include "engine.h"
#include "hero.h"

Result Drop::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());
    if (tile.is_door()) {
        return success();
    } else if (!tile.weapon) {
        // drop weapon on the tile
        std::swap(tile.weapon, engine.hero->type.weapon);
        // tile.is_weapon() returns true
        std::cout << "drop weapon\n";
        return success();
    }
    std::cout << "cannot drop weapon\n";
    return failure();
}