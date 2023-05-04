#include "staff_red.h"

#include "engine.h"
#include "hit.h"

StaffRed::StaffRed(int damage) : Weapon{"staff_red", damage} {}

void StaffRed::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
