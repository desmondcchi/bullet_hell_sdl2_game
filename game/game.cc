#include "game/game.h"

#include "SDL2/SDL.h"
#include "entities/player.h"

namespace game {

using ::entities::Player;

constexpr int kScreenWidth = 800;
constexpr int kScreenHeight = 600;

bool Game::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  window_ =
      SDL_CreateWindow("BenK 47: A Bullet Hell Game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, kScreenWidth, kScreenHeight, 0);
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
  if (SDL_PollEvent(&event_)) {
    switch (event_.type) {
      case SDL_QUIT:
        is_running_ = false;
        break;
    }
  }

  player_->HandleMovement(kScreenWidth, kScreenHeight);
}

void Game::Update() { player_->Update(); }

void Game::Render() {
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);

  player_->Render();

  SDL_RenderPresent(renderer_);
}

bool Game::IsRunning() const { return is_running_; }

}  // namespace game
