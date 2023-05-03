#pragma once

#include "actor.h"
#include "events.h"

class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};