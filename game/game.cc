#include "game/game.h"

#include <iostream>

#include "SDL2/SDL.h"
#include "entities/player.h"

namespace game {

using ::entities::Player;

bool Game::Init() {
  // TODO(desmondchi): Do not use SDL_Delay! This causes the window to not show
  // up.

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  window_ = SDL_CreateWindow("Bullet Hell Game", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!window_) {
    return false;
  }

  renderer_ = SDL_CreateRenderer(
      window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer_) {
    return false;
  }

  player_ = new Player(renderer_);

  is_running_ = true;
  return true;
}

void Game::GameLoop() {
  HandleEvents();
  Update();
  Render();
}

void Game::Shutdown() {
  SDL_DestroyWindowSurface(window_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

void Game::HandleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      is_running_ = false;
    }
  }
}

void Game::Update() {}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
  SDL_RenderClear(renderer_);

  player_->Render();

  SDL_RenderPresent(renderer_);
}

bool Game::IsRunning() const { return is_running_; }

}  // namespace game
