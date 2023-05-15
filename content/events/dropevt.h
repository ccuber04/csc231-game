#pragma once

#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class DropEvt : public Event {
public:
    DropEvt(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};