#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_monster(Monsters::muddy());
    engine.create_monster(Monsters::goblin());
    engine.create_monster(Monsters::skeleton());
    engine.create_monster(Monsters::demon_tiny());
    engine.create_monster(Monsters::zombie_small());
    engine.create_monster(Monsters::zombie());
    engine.create_monster(Monsters::zombie_big());
    engine.create_monster(Monsters::orc());
    engine.create_monster(Monsters::orc_masked());
    engine.create_monster(Monsters::orc_shaman());
    engine.create_monster(Monsters::ogre());
    engine.create_monster(Monsters::shy_guy());
    engine.create_monster(Monsters::demon());
    engine.create_monster(Monsters::demon_big());

    engine.create_hero(Heros::shy_guy);
    engine.run();
}
