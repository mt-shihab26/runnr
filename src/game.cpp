#include "game.hpp"

#include <raylib/raylib.h>

namespace runnr {

void Game::load() {
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
}

void Game::unload() {
    CloseWindow();
}

bool Game::running() {
    return !WindowShouldClose();
}

void Game::update() {
    float dt = GetFrameTime();

    camera.update(dt);
}

void Game::render() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera.get_object());

    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

    DrawFPS(10, 10);

    EndDrawing();
}

}
