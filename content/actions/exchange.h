#pragma once

#include "action.h"
#include "vec.h"

class Exchange : public Action {
public:
    Result perform(Engine& engine) override;
};