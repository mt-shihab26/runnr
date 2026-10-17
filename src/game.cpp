#include "game.hpp"

#include <raylib/raylib.h>

#include "core/config.hpp"

namespace runnr {

void Game::load() {
    InitWindow(m_width, m_height, m_title.c_str());
    SetTargetFPS(60);
    for (Entity *entity : entities) {
        entity->load();
    }
}

void Game::unload() {
    for (Entity *entity : entities) {
        entity->unload();
    }
    CloseWindow();
}

bool Game::running() {
    return !WindowShouldClose();
}

void Game::update() {
    float dt = GetFrameTime();
    for (Entity *entity : entities) {
        entity->update(dt);
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BACKGROUND_COLOR);
    BeginMode3D(m_camera.get_object());
    for (Entity *entity : entities) {
        entity->draw();
    }
    EndMode3D();
    for (Entity *entity : entities) {
        entity->ui();
    }
    DrawFPS(10, 10);
    EndDrawing();
}

}
