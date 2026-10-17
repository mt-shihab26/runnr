#pragma once

#include <raylib/raylib.h>

namespace runnr {

class Entity {
  public:
    virtual ~Entity() = default;

    virtual void load() {}
    virtual void unload() {}
    virtual void update([[maybe_unused]] float dt) {}
    virtual void draw() {}
    virtual void ui() {}
};

}
