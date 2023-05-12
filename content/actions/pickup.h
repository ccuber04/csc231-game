#pragma once

#include "action.h"
#include "vec.h"

class PickUp : public Action {
public:
    Result perform(Engine& engine) override;
};