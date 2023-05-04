#include "staff_green.h"

#include "engine.h"
#include "hit.h"

StaffGreen::StaffGreen(int damage) : Weapon{"staff_green", damage} {}

void StaffGreen::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
