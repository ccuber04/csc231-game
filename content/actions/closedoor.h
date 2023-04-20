#pragma once

#include "action.h"
#include "vec.h"

class CloseDoor : public Action {
public:
    Result perform(Engine& engine) override;
};