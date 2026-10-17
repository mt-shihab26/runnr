#pragma once

#include "core/entity.hpp"
#include "core/mode.hpp"

namespace runnr {

class Menu : public Entity {
  public:
    Menu(Mode &mode) : m_mode(mode) {};

    void load();
    void unload();
    void update(float dt);
    void draw();
    void ui();

  private:
    Mode m_mode;
};

}
