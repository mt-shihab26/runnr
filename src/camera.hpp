#pragma once

#include <raylib/raylib.h>

namespace runnr {

class Camera {
  public:
    Camera();

    void update(float dt);

    Camera3D &get_object() { return object; };

  private:
    Camera3D object;
};

}
