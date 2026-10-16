#include <raylib/raylib.h>

#include "camera.hpp"

namespace runnr {

Camera::Camera() {
    object.position = Vector3{0.0f, 10.0f, 10.0f}; // Camera position
    object.target = Vector3{0.0f, 0.0f, 0.0f};     // Camera looking at point
    object.up = Vector3{0.0f, 1.0f, 0.0f};         // Camera up vector (rotation towards target)
    object.fovy = 45.0f;                           // Camera field-of-view Y
    object.projection = CAMERA_PERSPECTIVE;        // Camera mode type
}

void Camera::update(float dt) {
    // x and z movements
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 delta = GetMouseDelta();

        object.position.x -= delta.x * zoom;
        object.position.z -= delta.y * zoom;

        object.target.x -= delta.x * zoom;
        object.target.z -= delta.y * zoom;
    }
}

}
