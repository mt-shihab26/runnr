#pragma once

#include <vector>

#include "core/entity.hpp"
#include "core/mode.hpp"

#include "entities/camera.hpp"
#include "entities/floor.hpp"
#include "entities/player.hpp"

namespace runnr {

class Game {
  public:
    void load();
    void unload();
    bool running();
    void update();
    void draw();

  private:
    Mode m_mode = Mode::MENU;

    float m_width = 1600;
    float m_height = 900;

    Camera m_camera;
    Player m_player{m_mode};
    Floor m_floor{m_camera};

    std::vector<Entity *> entities{&m_floor, &m_player, &m_camera};
};

}
