#pragma once

#include "actor.h"
#include "engine.h"
#include "events.h"

class Hit : public Event {
public:
    Hit(Actor& actor, int damage);
    void execute(Engine& engine) override;

private:
    Actor& actor;
    int damage;
};