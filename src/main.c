#include <raylib.h>

const int window_width = 1600;
    const int window_height = 900;

static void init(void) {
    InitWindow(window_width, window_height, "runnr.");
}

static void close(void) {
    CloseWindow();
}

static void run(void) {
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
