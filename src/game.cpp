#include "game.hpp"

#include <raylib/raylib.h>

namespace runnr {

Game::Game() {
    entities = {player, camera};
}

void Game::load() {
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);

    player.load();
}

void Game::unload() {
    player.unload();

    CloseWindow();
}

bool Game::running() {
    return !WindowShouldClose();
}

void Game::update() {
    float dt = GetFrameTime();

    camera.update(dt);
    player.update(dt);
}

void Game::render() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera.get_object());

    player.render();

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

    DrawFPS(10, 10);

    EndDrawing();
}

}
