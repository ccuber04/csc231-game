#include "pickup.h"

#include <cmath>
#include <iostream>

#include "engine.h"

Result PickUp::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());
    if (tile.weapon->name != "none" &&
        actor->weapon->name == "none") {  // && !actor->weapon
        // pick up weapon
        std::swap(tile.weapon, actor->weapon);

        Sprite& weapon_sprite = tile.weapon->sprite;
        int sign = std::copysign(1, weapon_sprite.angle);
        // int right_displace = (tile.sprite.size.x - weapon_sprite.size.x) /
        // -2; int left_displace = (tile.sprite.size.x - weapon_sprite.size.x) /
        // 2;

        if (sign == 1) {
            // weapon_sprite.shift += Vec{right_displace, 0};
            weapon_sprite.angle = 20;
        } else {
            // weapon_sprite.shift += Vec{left_displace, 0};
            weapon_sprite.flip = false;
            weapon_sprite.angle = -20;
        }
        return success();
    }
    return failure();
}
