#include <raylib/raylib.h>
#include <raylib/rlgl.h>

#include "floor.hpp"

namespace runnr {

void Floor::load() {}

void Floor::unload() {}

void Floor::update([[maybe_unused]] float dt) {
    m_size.y = 2.0f * static_cast<float>(rlGetCullDistanceFar());
}

void Floor::draw() {
    DrawPlane(Vector3{m_left.x, m_left.y, m_camera.get_object().position.z}, m_size, RED);
    DrawPlane(m_middle, m_size, GREEN);
    DrawPlane(m_right, m_size, BLUE);
}

void Floor::ui() {
}
}
