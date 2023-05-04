#include "rest.h"

#include "actor.h"
#include "randomness.h"

Result Rest::perform(Engine&) {
    // maybe add randomization for when rest adds health
    if (probability(75) && actor->health < actor->max_health) {
        actor->health += 1;
    }
    return success();
}
