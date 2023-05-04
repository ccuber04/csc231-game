#pragma once

#include "weapon.h"

class StaffGreen : public Weapon {
public:
    StaffGreen(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};