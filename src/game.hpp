#pragma once

#include <raylib/raylib.h>

#include "camera.hpp"

namespace runnr {

class Game {
  public:
    void load() {
        InitWindow(width, height, "runnr.");
        SetTargetFPS(60);
    }

    void unload() {
        CloseWindow();
    }

    void update() {
    }

    void render() {
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

    bool running() {
        return !WindowShouldClose();
    }

  private:
    float width = 1600;
    float height = 900;

    runnr::Camera camera;

    Vector3 cubePosition{0.0f, 0.0f, 0.0f};
};

}
