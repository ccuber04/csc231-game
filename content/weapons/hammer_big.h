#pragma once

#include "weapon.h"

class HammerBig : public Weapon {
public:
    HammerBig(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};