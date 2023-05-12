#pragma once

#include "actor.h"
#include "events.h"

class Drop;

class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};