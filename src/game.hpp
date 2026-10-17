#pragma once

#include <string>

#include "camera.hpp"
#include "player.hpp"

namespace runnr {

class Game {
  public:
    void load();
    void unload();
    bool running();
    void update();
    void render();

  private:
    std::string title = "runnr.";

    float width = 1600;
    float height = 900;

    Camera camera;

    Player player;

    Vector3 cubePosition{0.0f, 0.0f, 0.0f};
};

}
