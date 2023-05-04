#include "attack.h"

#include <iostream>

#include "actor.h"
#include "rest.h"

Attack::Attack(Actor& defender) : defender{defender} {}

Result Attack::perform(Engine&) {
    // if (actor->team != defender.team) {
    actor->attack(defender);
    return success();
    // }
    // return alternative(Rest{});
}