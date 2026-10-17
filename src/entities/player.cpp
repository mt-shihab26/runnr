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
    ModelAnimation animation = animations[index];

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
    DrawModelEx(model, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 1.0f, 0.0f}, 180.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
}

void Player::ui() {
    DrawText(animations[index].name, 10, 40, 30, GREEN);
}

};
