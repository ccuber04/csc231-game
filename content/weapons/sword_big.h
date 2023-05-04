#pragma once

#include "weapon.h"

class SwordBig : public Weapon {
public:
    SwordBig(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};