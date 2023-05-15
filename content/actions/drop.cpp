#include "drop.h"

#include <cmath>
#include <iostream>

#include "actor.h"
#include "engine.h"
#include "hero.h"
#include "rest.h"

Result Drop::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());

    if (tile.is_door()) {
        return failure();
    } else if (tile.weapon->name == "none") {
        // change actor weapon to weapon on tile
        std::swap(tile.weapon, actor->weapon);

        Sprite& weapon_sprite = tile.weapon->sprite;
        int sign = std::copysign(1, weapon_sprite.angle);
        int right_displace = (tile.sprite.size.x - weapon_sprite.size.x) / -2;
        int left_displace = (tile.sprite.size.x - weapon_sprite.size.x) / 2;

        if (sign == 1) {
            weapon_sprite.shift += Vec{right_displace, 0};
            weapon_sprite.angle = 0;
        } else {
            weapon_sprite.shift += Vec{left_displace, 0};
            weapon_sprite.flip = false;
            weapon_sprite.angle = 0;
        }
        return success();
    } else {
        return alternative(Rest{});
    }
}