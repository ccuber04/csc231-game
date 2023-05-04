#include "monsters.h"

#include "cleaver.h"
#include "engine.h"
#include "hero.h"
#include "knife.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "spear.h"
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

MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<Cleaver>(1),
            default_behavior};
}

MonsterType skeleton() {
    int health = 2;
    return {"skeleton", default_speed, health, std::make_shared<Cleaver>(1),
            default_behavior};
}

MonsterType demon_tiny() {
    int health = 1;
    return {"demon_tiny", tiny_speed, health, std::make_shared<Cleaver>(1),
            default_behavior};
}
}  // namespace Monsters
