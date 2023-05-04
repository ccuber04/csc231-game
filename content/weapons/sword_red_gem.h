#pragma once

#include "weapon.h"

class SwordRedGem : public Weapon {
public:
    SwordRedGem(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};