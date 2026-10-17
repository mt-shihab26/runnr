#include <raylib/raylib.h>

#include "floor.hpp"

namespace runnr {

void Floor::load() {}

void Floor::unload() {}

void Floor::update([[maybe_unused]] float dt) {}

void Floor::draw() {
    DrawGrid(10, 1.0f);
}

void Floor::ui() {
}
}
