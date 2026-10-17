#pragma once

#include <raylib/raylib.h>

#include "core/entity.hpp"
#include "core/mode.hpp"

namespace runnr {

class Menu : public Entity {
  public:
    Menu(Mode &mode) : m_mode(mode) {};

    void update(float dt) override;
    void ui() override;

  private:
    Mode &m_mode;

    bool m_play_hovered = false;

    Rectangle get_play_button() const;
};

}
