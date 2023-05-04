#pragma once

#include "action.h"
#include "monstertype.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& monster);
MonsterType goblin();
MonsterType skeleton();
MonsterType demon_tiny();
MonsterType zombie_small();
MonsterType zombie();
MonsterType zombie_big();
MonsterType muddy();
MonsterType orc();
MonsterType orc_masked();
MonsterType orc_shaman();
MonsterType ogre();
MonsterType shy_guy();
MonsterType demon();
MonsterType demon_big();
}  // namespace Monsters
