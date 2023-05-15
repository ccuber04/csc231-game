#include "dropact.h"

#include <cmath>
#include <iostream>

#include "actor.h"
#include "dropevt.h"
#include "engine.h"
#include "hero.h"
#include "rest.h"

Result DropAct::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());

    if (tile.weapon->name == "none" && !tile.is_door()) {
        engine.events.add(DropEvt{*actor});
        return success();
    } else {
        return alternative(Rest{});
    }
}