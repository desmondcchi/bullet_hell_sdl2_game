#include "game/game.h"

#include "SDL2/SDL.h"
#include "entities/player.h"

namespace game {

using ::entities::Player;

bool Game::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  window_ =
      SDL_CreateWindow("BenK 47: A Bullet Hell Game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!window_) {
    return false;
  }

  renderer_ = SDL_CreateRenderer(window_, -1, 0);
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
        // case SDL_KEYDOWN:
        //   switch (event_.key.keysym.sym) {
        //     case SDLK_w:
        //       player_->Move(entities::Player::Direction::kUp);
        //       break;
        //     case SDLK_a:
        //       player_->Move(entities::Player::Direction::kLeft);
        //       break;
        //     case SDLK_s:
        //       player_->Move(entities::Player::Direction::kDown);
        //       break;
        //     case SDLK_d:
        //       player_->Move(entities::Player::Direction::kRight);
        //       break;
        //   }
        //   break;
    }

    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_W]) {
      player_->Move(entities::Player::Direction::kUp);
    }
    if (keystate[SDL_SCANCODE_A]) {
      player_->Move(entities::Player::Direction::kLeft);
    }
    if (keystate[SDL_SCANCODE_S]) {
      player_->Move(entities::Player::Direction::kDown);
    }
    if (keystate[SDL_SCANCODE_D]) {
      player_->Move(entities::Player::Direction::kRight);
    }
  }
}

void Game::Update() { player_->Update(); }

void Game::Render() {
  SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
  SDL_RenderClear(renderer_);

  player_->Render();

  SDL_RenderPresent(renderer_);
}

bool Game::IsRunning() const { return is_running_; }

}  // namespace game
