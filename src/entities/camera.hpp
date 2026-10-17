#pragma once

#include <raylib/raylib.h>

#include "core/entity.hpp"

namespace runnr {

class Camera : public Entity {
  public:
    void load() override;
    void update(float dt) override;

    const Camera3D &get_object() const { return object; }

  private:
    void set_default();

    void handle_reset();
    void handle_pan();
    void handle_orbit();
    void handle_zoom(float wheel);

    Camera3D object;
};

}
