#pragma once

#include "core/config.hpp"
#include "core/entity.hpp"

#include "entities/camera.hpp"

namespace runnr {

class Floor : public Entity {
  public:
    Floor(Camera &camera) : m_camera(camera) {};

    void update(float dt) override;
    void draw() override;

  private:
    Camera &m_camera;

    Vector2 m_size{3.0f * LANE_WIDTH, 0};
};

}
