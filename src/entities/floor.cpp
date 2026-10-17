#include <initializer_list>

#include <raylib/raylib.h>
#include <raylib/rlgl.h>

#include "floor.hpp"

namespace runnr {

void Floor::update([[maybe_unused]] float dt) {
    m_size.y = 2.0f * static_cast<float>(rlGetCullDistanceFar());
}

void Floor::draw() {
    float z = m_camera.get_object().position.z;

    DrawPlane(Vector3{0.0f, 0.0f, z}, m_size, FLOOR_COLOR);

    float half = m_size.y / 2.0f;
    for (float x : {LANE_MIN_X / 2.0f, LANE_MAX_X / 2.0f}) {
        DrawLine3D(Vector3{x, 0.01f, z - half}, Vector3{x, 0.01f, z + half}, LANE_LINE_COLOR);
    }
}

}
