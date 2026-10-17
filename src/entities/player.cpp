#include <string>

#include <raylib/raylib.h>

#include "player.hpp"

namespace runnr {

void Player::load() {
    m_model = LoadModel(m_path.c_str());
    m_model_animations = LoadModelAnimations(m_path.c_str(), &m_animations_count);
}

void Player::unload() {
    UnloadModelAnimations(m_model_animations, m_animations_count);
    UnloadModel(m_model);
}

void Player::update(float dt) {
    handle_animation_update(dt);
    handle_horizontal_movement(dt);
}

void Player::handle_horizontal_movement(float dt) {
    float min_lane_x = -4.0f;
    float max_lane_x = 4.0f;

    if (IsKeyPressed(KEY_LEFT)) {
        if (m_movement_target.x > min_lane_x) {
            m_movement_target.x += min_lane_x;
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (m_movement_target.x < max_lane_x) {
            m_movement_target.x += max_lane_x;
        }
    }

    float lange_fps = 1.0f;

    if (m_movement_target.x < m_position.x) {
        m_position.x -= (lange_fps * dt);
    }
    if (m_position.x < m_movement_target.x) {
        m_position.x += (lange_fps * dt);
    }
}

void Player::handle_animation_update(float dt) {
    ModelAnimation &animation = get_animation();

    const float m_fps = 30.0f;

    m_animation_keyframe += (m_fps * dt);
    if (animation.keyframeCount <= m_animation_keyframe) {
        m_animation_keyframe -= animation.keyframeCount;
        m_animation_index++;
    }

    if (14 <= m_animation_index) {
        m_animation_index = 0;
    }

    UpdateModelAnimation(m_model, animation, m_animation_keyframe);
}

void Player::draw() {
    DrawModelEx(m_model, m_position, m_rotation_axis, m_rotation_angle, m_scale, WHITE);
}

void Player::ui() {
    DrawText(get_animation().name, 10, 40, 30, GREEN);
}
};
