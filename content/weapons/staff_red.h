#pragma once

#include "weapon.h"

class StaffRed : public Weapon {
public:
    StaffRed(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};