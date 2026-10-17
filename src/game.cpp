#include "game.hpp"

#include <raylib/raylib.h>

namespace runnr {

Game::Game() {
    entities = {&player, &camera};
}

void Game::load() {
    InitWindow(width, height, title.c_str());
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

void Game::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera.get_object());
    for (Entity *entity : entities) {
        entity->render();
    }
    DrawGrid(10, 1.0f);
    EndMode3D();
    for (Entity *entity : entities) {
        entity->ui();
    }
    DrawFPS(10, 10);
    EndDrawing();
}

}
