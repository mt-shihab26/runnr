#pragma once

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

    Vector3 m_left{-4.0f, 0.0f, 0.0f};
    Vector3 m_middle{0.0f, 0.0f, 0.0f};
    Vector3 m_right{4.0f, 0.0f, 0.0f};

    Vector2 m_size{4.0f, 0};
};

}
