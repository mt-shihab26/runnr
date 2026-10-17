#pragma once

#include <string>

#include <raylib/raylib.h>

#include "core/entity.hpp"
#include "support/path.hpp"

namespace runnr {

enum PlayerAnimation {
    ROBOT_DANCE = 0,
    ROBOT_DEATH = 1,
    ROBOT_IDLE = 2,
    ROBOT_JUMP = 3,
    ROBOT_NO = 4,
    ROBOT_PUNCH = 5,
    ROBOT_RUNNING = 6,
    ROBOT_SITTING = 7,
    ROBOT_STANDING = 8,
    ROBOT_THUMBS_UP = 9,
    ROBOT_WALKING = 10,
    ROBOT_WALK_JUMP = 11,
    ROBOT_WAVE = 12,
    ROBOT_YES = 13,
};

class Player : public Entity {
  public:
    void load() override;
    void unload() override;
    void update(float dt) override;
    void draw() override;
    void ui() override;

  private:
    std::string path = project_path("assets/models/player.glb");
    Model model;
    int count = 0;
    ModelAnimation *animations = nullptr;
    int index = PlayerAnimation::ROBOT_JUMP;
    float frame = 0.0f;
    const float fps = 30.0f;
};

}
