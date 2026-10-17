#pragma once

#include <raylib/raylib.h>

namespace runnr {

class Player {
  public:
    void load();
    void unload();
    void update(float dt);
    void render();

  private:
    Model model;
    int count = 0;
    ModelAnimation *animations = nullptr;
    int index = 0;
    float frame = 0.0f;
    const float fps = 30.0f;
};

}
