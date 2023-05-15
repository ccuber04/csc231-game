#pragma once

#include "cleaver.h"
#include "closedoor.h"
#include "drop.h"
#include "hammer_big.h"
#include "herotype.h"
#include "knife.h"
#include "mace.h"
#include "move.h"
#include "none.h"
#include "pickup.h"
#include "rest.h"
#include "spear.h"
#include "staff_red.h"
#include "sword_big.h"

namespace Heros {

// Reaction = std::function<std::unique_ptr<Action>()>
// std:: unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"A",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"W",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"S",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"D",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},
    {"Q", []() { return std::make_unique<Drop>(); }},
    {"Space", []() { return std::make_unique<PickUp>(); }}

};

constexpr int default_speed{8};
const HeroType shy_guy{"shy-guy", default_speed, 20,
                       std::make_shared<HammerBig>(2), keybindings};
const HeroType elf{"elf", default_speed, 10, std::make_shared<None>(),
                   keybindings};
const HeroType knight{"knight", default_speed, 10, std::make_shared<None>(),
                      keybindings};
const HeroType wizard{"wizard", default_speed, 10, std::make_shared<None>(),
                      keybindings};
const HeroType dragon{"dragon", default_speed, 10, std::make_shared<None>(),
                      keybindings};

}  // namespace Heros
