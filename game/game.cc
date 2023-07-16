#include "game/game.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace game {

int Game::Init() {
  // TODO: Do not use SDL_Delay! This causes the window to not show up.
  
  std::cout << "DEBUG: Initializing game.\n";

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "DEBUG: Failed to initialize the SDL2 library.\n";
    return 1;
  }

  window_ = SDL_CreateWindow("Bullet Hell Game", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, 800, 600, 0);

  if (!window_) {
    std::cout << "DEBUG: Failed to create window!\n";
    return 1;
  }

  window_surface_ = SDL_GetWindowSurface(window_);

  if (!window_surface_) {
    std::cout << "DEBUG: Failed to get window surface!\n";
    return 1;
  }

  SDL_UpdateWindowSurface(window_);
  is_running_ = true;

  std::cout << "DEBUG: Finished initializing game!\n";

  return 0;
}

void Game::GameLoop() {
  HandleEvents();
  Update();
  Render();
}

void Game::Shutdown() {
  std::cout << "DEBUG: Shutting down game.\n";
  SDL_DestroyWindowSurface(window_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
  std::cout << "DEBUG: Finished shutting down game!\n";
}

void Game::HandleEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      std::cout << "DEBUG: Quitting game.\n";
      is_running_ = false;
    }
  }
}

void Game::Update() {}

void Game::Render() {}

bool Game::IsRunning() const {
  return is_running_;
}
}  // namespace game
