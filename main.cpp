#include "game.h"
#include <memory>

auto main() -> int
{
    auto game = std::make_unique<Game>();

    game->init();

    game->run();
}

