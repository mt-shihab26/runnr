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

Camera::~Camera() {
}

}
