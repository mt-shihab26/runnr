
#include <raylib/raylib.h>

#include "log.hpp"
#include "player.hpp"

namespace runnr {

void Player::load() {
    model = LoadModel("assets/models/robot.glb");
    animations = LoadModelAnimations("assets/models/robot.glb", &count);
    for (int i = 0; i < count; i++)
        log_info("{}: {}", i, animations[i].name);
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
