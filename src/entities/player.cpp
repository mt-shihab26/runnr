#include <string>

#include <raylib/raylib.h>

#include "core/config.hpp"

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
    if (IsKeyPressed(KEY_LEFT)) {
        if (m_movement_target.x > LANE_MIN_X) {
            m_movement_target.x += LANE_MIN_X;
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (m_movement_target.x < LANE_MIN_X) {
            m_movement_target.x += LANE_MIN_X;
        }
    }
    if (m_movement_target.x < m_position.x) {
        m_position.x -= (PLAYER_SWITCH_SPEED * dt);
    }
    if (m_position.x < m_movement_target.x) {
        m_position.x += (PLAYER_SWITCH_SPEED * dt);
    }
}

void Player::handle_animation_update(float dt) {
    ModelAnimation &animation = get_animation();

    m_animation_keyframe += (PLAYER_ANIMATION_SPEED * dt);
    if (animation.keyframeCount <= m_animation_keyframe) {
        m_animation_keyframe -= animation.keyframeCount;
        m_animation_index++;
    }

    if (m_animations_count <= m_animation_index) {
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
