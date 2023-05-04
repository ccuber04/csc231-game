#pragma once

#include "weapon.h"

class SpikedClub : public Weapon {
public:
    SpikedClub(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};