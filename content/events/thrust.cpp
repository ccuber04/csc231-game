#include "thrust.h"

#include "hit.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      copy{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.shift.y -= sprite.size.y / 4;
    sprite.shift.x -= sprite.size.x / 2;

    if (direction == Vec{1, 0}) {
        sprite.angle = 90;
    } else if (direction == Vec{-1, 0}) {
        sprite.angle = -90;
    } else if (direction == Vec{0, 1}) {
        sprite.angle = 0;
        this->direction = direction * -1;
    } else {
        sprite.angle = 180;
        this->direction = direction * -1;
    }
}

void Thrust::execute(Engine&) {
    sprite.shift += direction;
}

void Thrust::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}