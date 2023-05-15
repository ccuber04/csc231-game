#include "die.h"

#include <cmath>
#include <iostream>

#include "engine.h"
Die::Die(Actor& actor) : actor{actor} {}

void Die::execute(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor.get_position());

    // drop actors weapon on tile
    if (tile.weapon->name == "none") {
        std::swap(tile.weapon, actor.weapon);

        Sprite& weapon_sprite = tile.weapon->sprite;
        int sign = std::copysign(1, weapon_sprite.angle);
        int right_displace =
            -1 + (tile.sprite.size.x - weapon_sprite.size.x) / -2;
        int left_displace = 1 + (tile.sprite.size.x - weapon_sprite.size.x) / 2;

        if (sign == 1) {
            weapon_sprite.shift += Vec{right_displace, 0};
            weapon_sprite.angle = 0;
        } else {
            weapon_sprite.shift += Vec{left_displace, 0};
            weapon_sprite.flip = false;
            weapon_sprite.angle = 0;
        }
    }

    // remove actor from game
    actor.alive = false;
    engine.dungeon.remove_actor(actor.get_position());
}