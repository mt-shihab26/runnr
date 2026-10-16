#include "camera.hpp"
#include <raylib/raylib.h>

int main(void) {
    const int screen_width = 1600;
    const int screen_height = 900;

    InitWindow(screen_width, screen_height, "runnr.");

    runnr::Camera camera;

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

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

    CloseWindow();

    return 0;
}
