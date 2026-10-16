#pragma once

#include <raylib/raylib.h>

namespace runnr {

class Camera {
  public:
    Camera();

    void update(float dt);

    Camera3D &get_object() { return object; };

  private:
    void set_default();

    void handle_reset();
    void handle_pan();
    void handle_orbit();
    void handle_zoom(float wheel);

    Camera3D object;
};

}
