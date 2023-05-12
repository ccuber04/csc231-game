#include "pickup.h"

#include <iostream>

#include "engine.h"

Result PickUp::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());
    if (tile.weapon && engine.hero->type.weapon) {
        // pick up weapon

        //    assign weapon to actor
        return success();
        std::cout << "pick up weapon\n";
    }
    std::cout << "cannot pick up weapon\n";
    return failure();
}
