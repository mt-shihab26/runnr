#include <raylib/raylib.h>

#include "floor.hpp"

namespace runnr {

void Floor::load() {}

void Floor::unload() {}

void Floor::update([[maybe_unused]] float dt) {}

void Floor::draw() {
    DrawGrid(12, 1.0f);

    DrawPlane(left, size, RED);
    DrawPlane(middle, size, GREEN);
    DrawPlane(right, size, BLUE);
}

void Floor::ui() {
}
}
