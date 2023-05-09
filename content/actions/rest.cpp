#include "rest.h"

#include "actor.h"
#include "randomness.h"

Result Rest::perform(Engine&) {
    if (probability(50) && actor->health < actor->max_health) {
        actor->health += 1;
    }
    return success();
}
