#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    for (int i{0}; i < 2; ++i) {
        // tiny speed and health
        engine.create_monster(Monsters::demon_tiny());
        engine.create_monster(Monsters::zombie_small());

        // tiny speed, default health
        engine.create_monster(Monsters::orc_shaman());

        // tiny speed, big health
        engine.create_monster(Monsters::shy_guy());

        // default speed and health
        engine.create_monster(Monsters::muddy());
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::skeleton());
        engine.create_monster(Monsters::zombie());
        engine.create_monster(Monsters::orc());
        engine.create_monster(Monsters::ogre());
        engine.create_monster(Monsters::demon());

        // default speed, big health
        engine.create_monster(Monsters::orc_masked());

        // big speed and health
        engine.create_monster(Monsters::zombie_big());
        engine.create_monster(Monsters::demon_big());
    }

    // set tiles weapons to none
    for (int y{0}; y < engine.dungeon.tiles.height; ++y) {
        for (int x{0}; x < engine.dungeon.tiles.width; ++x) {
            Tile& tile = engine.dungeon.tiles(Vec{x, y});
            if (tile.walkable) {
                tile.weapon = std::make_shared<None>();
            }
        }
    }
    // create hero
    engine.create_hero(Heros::shy_guy);
    engine.run();
}
