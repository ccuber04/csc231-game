#include "attack.h"

#include <iostream>

#include "actor.h"
#include "rest.h"

Attack::Attack(Actor& defender) : defender{defender} {}

Result Attack::perform(Engine&) {
    actor->attack(defender);
    return success();
}