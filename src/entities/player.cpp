#include <raylib/raylib.h>

#include "player.hpp"

namespace runnr {

void Player::load() {
    model = LoadModel("assets/models/player.glb");
    animations = LoadModelAnimations("assets/models/player.glb", &count);
}

void Player::unload() {
    UnloadModelAnimations(animations, count);
    UnloadModel(model);
}

void Player::update(float dt) {
    ModelAnimation animation = animations[index];

    frame += (fps * dt);
    if (animation.keyframeCount <= frame)
        frame -= animation.keyframeCount;

    UpdateModelAnimation(model, animation, frame);
}

void Player::render() {
    DrawModelEx(model, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 1.0f, 0.0f}, 180.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
}

};
