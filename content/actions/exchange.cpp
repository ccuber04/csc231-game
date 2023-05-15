#include "exchange.h"

#include <cmath>
#include <iostream>

#include "engine.h"

Result Exchange::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());
    if (tile.weapon->name != "none") {
        // pick up weapon
        std::swap(tile.weapon, actor->weapon);

        Sprite& tile_weapon = tile.weapon->sprite;
        Sprite& actor_weapon = actor->weapon->sprite;
        int sign = std::copysign(1, tile_weapon.angle);

        int right_displace =
            -1 + (tile.sprite.size.x - tile_weapon.size.x) / -2;
        int left_displace = 1 + (tile.sprite.size.x - tile_weapon.size.x) / 2;

        actor_weapon.angle = sign * 20;

        if (sign == 1) {
            // adjust tile weapon
            tile_weapon.shift += Vec{right_displace, 0};
            tile_weapon.angle = 0;

            // adjust actor weapon
            actor_weapon.shift += Vec{sign * actor_weapon.size.x / 8, 0};
        } else {
            // adjust tile weapon
            tile_weapon.shift += Vec{sign * actor_weapon.size.x / 8, 0};
            tile_weapon.flip = false;
            tile_weapon.angle = 0;

            // adjust actor weapon
            actor_weapon.shift += Vec{left_displace, 0};
            actor_weapon.flip = true;
        }
        return success();
    }
    return failure();
}
