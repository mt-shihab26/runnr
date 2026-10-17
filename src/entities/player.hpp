#pragma once

#include <string>

#include <raylib/raylib.h>

#include "core/entity.hpp"
#include "core/mode.hpp"
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
    Player(Mode &mode) : m_mode(mode) {};

    void load() override;
    void unload() override;
    void update(float dt) override;
    void draw() override;
    void ui() override;

  private:
    Mode &m_mode;

    std::string m_path = project_path("assets/models/player.glb");
    Model m_model;
    int m_animations_count = 0;
    ModelAnimation *m_model_animations = nullptr;
    int m_animation_index = PlayerAnimation::ROBOT_RUNNING;
    float m_animation_keyframe = 0.0f;

    Vector3 m_movement_target{0.0f, 0.0f, 0.0f};

    Vector3 m_position{0.0f, 0.0f, 0.0f};
    Vector3 m_rotation_axis{0.0f, 1.0f, 0.0f};
    float m_rotation_angle = 180.0f;
    Vector3 m_scale{1.0f, 1.0f, 1.0f};

    ModelAnimation &get_animation() { return m_model_animations[m_animation_index]; }

    void handle_animation_select();
    void handle_animation_update(float dt);
    void handle_horizontal_movement(float dt);
};

}
