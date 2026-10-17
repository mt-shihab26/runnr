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

  private:
    Vector3 left{-4.0f, 0.0f, 0.0f};
    Vector3 middle{0.0f, 0.0f, 0.0f};
    Vector3 right{4.0f, 0.0f, 0.0f};

    Vector2 size{4.0f, 0};
};

}
