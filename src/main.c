#include <raylib.h>

const int window_width = 1600;
const int window_height = 900;

void init() {
    InitWindow(window_width, window_height, "runnr.");
}

void close() {
    CloseWindow();
}

void run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}

int main() {
    init();
    run();
    close();
    return 0;
}
