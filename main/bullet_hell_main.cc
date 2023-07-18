#include <iostream>

#include "SDL2/SDL.h"
#include "absl/flags/flag.h"
#include "game/game.h"
#include "absl/flags/flag.h"

ABSL_FLAG(int, fps, 60, "FPS for the game.");

int main(int argc, char* argv[]) {
  game::Game& game = game::Game::GetInstance();

  if (!game.Init()) {
    game.Shutdown();
    return 1;
  }

  int frame_delay = 1000 / absl::GetFlag(FLAGS_fps);
  Uint32 frame_start;
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

  return 0;
}