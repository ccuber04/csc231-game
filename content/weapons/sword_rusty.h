#pragma once

#include "weapon.h"

class SwordRusty : public Weapon {
public:
    SwordRusty(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};