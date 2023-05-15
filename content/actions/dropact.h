#pragma once

#include "action.h"
#include "vec.h"

class DropAct : public Action {
public:
    Result perform(Engine& engine) override;
};