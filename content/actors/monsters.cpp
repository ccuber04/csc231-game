#include "monsters.h"

#include "axe.h"
#include "cleaver.h"
#include "engine.h"
#include "hammer.h"
#include "hero.h"
#include "knife.h"
#include "mace.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "spear.h"
#include "staff_red.h"
#include "sword.h"
#include "sword_red_gem.h"
#include "wander.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // if monster can see hero
    if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    // if monster cannot see hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    }
    return std::make_unique<Rest>();
}

constexpr int default_speed{8};
constexpr int tiny_speed{16};
constexpr int big_speed{4};

constexpr int tiny_health{2};
constexpr int default_health{3};
constexpr int big_health{5};

MonsterType goblin() {
    return {"goblin", default_speed, default_health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType skeleton() {
    return {"skeleton", default_speed, default_health,
            std::make_shared<Sword>(2), default_behavior};
}

MonsterType demon_tiny() {
    return {"demon_tiny", tiny_speed, tiny_health, std::make_shared<Mace>(2),
            default_behavior};
}

MonsterType zombie_small() {
    return {"zombie_small", default_speed, tiny_health,
            std::make_shared<None>(), default_behavior};
}

MonsterType zombie() {
    return {"zombie", default_speed, default_health, std::make_shared<None>(),
            default_behavior};
}

MonsterType zombie_big() {
    return {"zombie_big", big_speed, big_health, std::make_shared<None>(),
            default_behavior};
}

MonsterType muddy() {
    return {"muddy", default_speed, default_health, std::make_shared<None>(),
            default_behavior};
}

MonsterType orc() {
    return {"orc", default_speed, default_health, std::make_shared<Cleaver>(2),
            default_behavior};
}

MonsterType orc_masked() {
    return {"orc_masked", default_speed, big_health, std::make_shared<Axe>(2),
            default_behavior};
}

MonsterType orc_shaman() {
    return {"orc_shaman", tiny_speed, default_health,
            std::make_shared<StaffRed>(1), default_behavior};
}

MonsterType ogre() {
    return {"ogre", big_speed, big_health, std::make_shared<Hammer>(4),
            default_behavior};
}

MonsterType shy_guy() {
    return {"necromancer", tiny_speed, big_health,
            std::make_shared<SwordRedGem>(3), default_behavior};
}

MonsterType demon() {
    return {"demon", default_speed, default_health, std::make_shared<None>(),
            default_behavior};
}

MonsterType demon_big() {
    return {"demon_big", big_speed, big_health, std::make_shared<None>(),
            default_behavior};
}

}  // namespace Monsters
