#include <cstdlib>
#include <iostream>

#include "SDL2/SDL.h"
#include "game/game.h"

constexpr int fps = 60;

int main(int argc, char* argv[]) {
  game::Game& game = game::Game::GetInstance();

  game.Init();

  int frame_delay = 1000 / fps;
  uint64_t frame_start;
  int frame_time;

  while (game.IsRunning()) {
    frame_start = SDL_GetTicks();

    game.GameLoop();

    frame_time = SDL_GetTicks() - frame_start;

    // Limit frame rate.
    if (frame_delay > frame_time) {
      SDL_Delay(frame_delay - frame_time);
    }
  }

  game.Shutdown();

  return EXIT_SUCCESS;
}
