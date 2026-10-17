#include <raylib/raylib.h>
#include <raylib/rlgl.h>

#include "floor.hpp"

namespace runnr {

void Floor::load() {
}

void Floor::unload() {}

void Floor::update([[maybe_unused]] float dt) {
    size.y = 2.0f * static_cast<float>(rlGetCullDistanceFar());
}

void Floor::draw() {
    DrawPlane(left, size, RED);
    DrawPlane(middle, size, GREEN);
    DrawPlane(right, size, BLUE);
}

void Floor::ui() {
}
}
