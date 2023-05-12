#pragma once

#include "action.h"
#include "vec.h"

class Drop : public Action {
public:
    Result perform(Engine& engine) override;
};