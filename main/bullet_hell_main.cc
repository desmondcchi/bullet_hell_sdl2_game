#include <iostream>

#include "game/game.h"

int main(int argc, char* argv[]) {
  game::Game& game = game::Game::GetInstance();

  if (!game.Init()) {
    std::cout << "DEBUG: Error initializing game.\n";

    game.Shutdown();
    return 1;
  }

  while (game.IsRunning()) {
    game.GameLoop();
  }

  game.Shutdown();

  return 0;
}