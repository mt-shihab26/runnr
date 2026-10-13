#include <raylib.h>

int main() {
    InitWindow(500, 500, "Hello runnr.");

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
    }

    CloseWindow();

    return 0;
}
