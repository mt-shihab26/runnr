#include <cmath>

#include <raylib/raylib.h>
#include <raylib/raymath.h>

#include "camera.hpp"

namespace runnr {

Camera::Camera() {
    set_default();
}

void Camera::update(float _) {
    if (IsKeyPressed(KEY_R)) {
        handle_reset();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        handle_pan();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        handle_orbit();
    }
}

void Camera::set_default() {
    object.position = Vector3{0.0f, 10.0f, 10.0f};
    object.target = Vector3{0.0f, 0.0f, 0.0f};
    object.up = Vector3{0.0f, 1.0f, 0.0f};
    object.fovy = 45.0f;
    object.projection = CAMERA_PERSPECTIVE;
}

void Camera::handle_reset() {
    set_default();
}

// Left drag: slide camera and target together along the ground
void Camera::handle_pan() {
    constexpr float zoom = 0.025f;

    Vector2 delta = GetMouseDelta();

    Vector3 forward = Vector3Subtract(object.target, object.position);
    forward.y = 0.0f;
    forward = Vector3Normalize(forward);
    Vector3 right = Vector3{-forward.z, 0.0f, forward.x};

    Vector3 move = Vector3Add(Vector3Scale(right, -delta.x * zoom), Vector3Scale(forward, delta.y * zoom));

    object.position = Vector3Add(object.position, move);
    object.target = Vector3Add(object.target, move);
}

// Right drag: rotate the camera around the target
void Camera::handle_orbit() {
    constexpr float orbit_speed = 0.005f;
    constexpr float max_pitch = 89.0f * DEG2RAD;

    Vector2 delta = GetMouseDelta();

    if (delta.x == 0.0f && delta.y == 0.0f) {
        return;
    }

    Vector3 offset = Vector3Subtract(object.position, object.target);
    float distance = Vector3Length(offset);

    float yaw = atan2f(offset.x, offset.z);
    float pitch = asinf(offset.y / distance);

    yaw -= delta.x * orbit_speed;
    pitch = Clamp(pitch + delta.y * orbit_speed, -max_pitch, max_pitch);

    offset = Vector3{
        distance * cosf(pitch) * sinf(yaw),
        distance * sinf(pitch),
        distance * cosf(pitch) * cosf(yaw),
    };

    object.position = Vector3Add(object.target, offset);
}

}
