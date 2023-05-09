#include "swing.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 6;

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},
      sprite{sprite},
      copy{sprite},
      direction{direction},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta_angle = 135 / (duration - 1);
    } else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta_angle = -135 / (duration - 1);
    } else if (direction == Vec{0, 1}) {
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta_angle = 90 / (duration - 1) * sign;
        sprite.shift.y -= 12;
    } else {
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta_angle = 90 / (duration - 1) * sign;
        sprite.shift.y -= 6;
        sprite.shift.x -= 2;
    }
}

void Swing::execute(Engine&) {
    sprite.angle = starting_angle + delta_angle * frame_count;
}

void Swing::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}