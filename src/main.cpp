#include <raylib/raylib.h>

#include "game.hpp"

int main(void) {
    runnr::Game game;

    game.load();

    while (game.running()) {
        game.update();
        game.render();
    }

    game.unload();

    return 0;
}
