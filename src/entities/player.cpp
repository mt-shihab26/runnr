#include <string>

#include <raylib/raylib.h>

#include "player.hpp"

namespace runnr {

void Player::load() {
    model = LoadModel(path.c_str());
    animations = LoadModelAnimations(path.c_str(), &count);
}

void Player::unload() {
    UnloadModelAnimations(animations, count);
    UnloadModel(model);
}

void Player::update(float dt) {
    handle_animation_update(dt);
}

void Player::handle_animation_update(float dt) {
    ModelAnimation &animation = get_animation();

    frame += (fps * dt);
    if (animation.keyframeCount <= frame) {
        frame -= animation.keyframeCount;
        index++;
    }

    if (14 <= index) {
        index = 0;
    }

    UpdateModelAnimation(model, animation, frame);
}

void Player::draw() {
    DrawModelEx(model, position, rotation_axis, rotation_angle, scale, WHITE);
}

void Player::ui() {
    DrawText(get_animation().name, 10, 40, 30, GREEN);
}
};
