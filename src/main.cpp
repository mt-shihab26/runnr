#include <raylib/raylib.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "game.hpp"

static void frame(void *arg) {
    auto *game = static_cast<runnr::Game *>(arg);

    game->update();
    game->draw();
}

int main(void) {
    runnr::Game game;

    game.load();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(frame, &game, 0, true);
#else
    while (game.running()) {
        frame(&game);
    }
#endif

    game.unload();

    return 0;
}
