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

    constexpr float thickness = 1.0f;

    rlDrawRenderBatchActive();
    rlDisableBackfaceCulling();
    DrawCube(Vector3{0.0f, -thickness / 2.0f, z}, m_size.x, thickness, m_size.y, FLOOR_COLOR);
    rlDrawRenderBatchActive();
    rlEnableBackfaceCulling();

    float half = m_size.y / 2.0f;
    for (float x : {LANE_MIN_X / 2.0f, LANE_MAX_X / 2.0f}) {
        DrawLine3D(Vector3{x, 0.01f, z - half}, Vector3{x, 0.01f, z + half}, LANE_LINE_COLOR);
    }
}

}
