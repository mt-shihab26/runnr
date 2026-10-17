#pragma once

#include "core/config.hpp"
#include "core/entity.hpp"

#include "entities/camera.hpp"

namespace runnr {

class Floor : public Entity {
  public:
    Floor(Camera &camera) : m_camera(camera) {};

    void load() override;
    void unload() override;
    void update(float dt) override;
    void draw() override;
    void ui() override;

  private:
    Camera &m_camera;

    Vector3 m_left{LANE_MIN_X, 0.0f, 0.0f};
    Vector3 m_middle{0.0f, 0.0f, 0.0f};
    Vector3 m_right{LANE_MAX_X, 0.0f, 0.0f};

    Vector2 m_size{LANE_WIDTH, 0};
};

}
