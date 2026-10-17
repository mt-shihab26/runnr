#pragma once

#include <string>
#include <vector>

#include "core/entity.hpp"

#include "entities/camera.hpp"
#include "entities/floor.hpp"
#include "entities/player.hpp"

namespace runnr {

class Game {
  public:
    Game();

    void load();
    void unload();
    bool running();
    void update();
    void draw();

  private:
    std::string title = "runnr.";

    float width = 1600;
    float height = 900;

    Floor floor;
    Camera camera;
    Player player;

    std::vector<Entity *> entities{&floor, &player, &camera};
};

}
