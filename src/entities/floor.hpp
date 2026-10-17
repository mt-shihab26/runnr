#pragma once

#include "core/entity.hpp"

namespace runnr {

class Floor : public Entity {
  public:
    void load() override;
    void unload() override;
    void update(float dt) override;
    void draw() override;
    void ui() override;
};

}
