#include "game/game.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "absl/log/check.h"
#include "entities/player.h"
#include "level/level.h"
#include "projectiles/carrot_gun_projectile.h"
#include "projectiles/projectile.h"
#include "util/audio_manager.h"

namespace game {

using ::entities::Player;
using ::level::Level;
using ::projectiles::CarrotGunProjectile;
using ::projectiles::Projectile;

constexpr int kScreenWidth = 1700;
constexpr int kScreenHeight = 1000;
constexpr int kTileWidth = 100;
constexpr int kTileHeight = 100;

void Game::Init() {
  CHECK_GE(SDL_Init(SDL_INIT_EVERYTHING), 0) << "Failed to initialize SDL2.";

  window_ =
      SDL_CreateWindow("BenK 47: A Bullet Hell Game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, kScreenWidth, kScreenHeight, 0);
  CHECK_NE(window_, nullptr) << "Failed to create window.";

  renderer_ = SDL_CreateRenderer(
      window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  CHECK_NE(renderer_, nullptr) << "Failed to create renderer.";

  CHECK_GE(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048), 0)
      << "Failed to open SDL_mixer.";

  // Add audio files here.
  audio_manager_ = std::make_unique<util::AudioManager>();
  audio_manager_->AddAudio("assets/player/ben.mp3");

  // Create player.
  int player_width = kTileWidth - 20;
  int player_height = kTileHeight - 20;
  player_ = std::make_unique<Player>((kScreenWidth - player_width) / 2.0f,
                                     (kScreenHeight - player_height) / 2.0f,
                                     player_width, player_height, 5, renderer_);

  // Initialize level.
  level_ = std::make_unique<Level>(
      "assets/tiles/", "game/levels/level_graph_1.txt",
      kScreenHeight / kTileHeight, kScreenWidth / kTileWidth, kScreenWidth,
      kScreenHeight, renderer_);

  is_running_ = true;
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
  SDL_Point temp;
  SDL_GetMouseState(&temp.x, &temp.y);
  SDL_FPoint mouse_position{static_cast<float>(temp.x),
                            static_cast<float>(temp.y)};

  if (SDL_PollEvent(&event_)) {
    switch (event_.type) {
      case SDL_QUIT:
        is_running_ = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        projectiles_.push_back(std::make_unique<CarrotGunProjectile>(
            SDL_FPoint{player_->GetPosition().x + player_->GetWidth() / 2,
                       player_->GetPosition().y + player_->GetHeight() / 2},
            mouse_position, renderer_));
        audio_manager_->PlayAudio("assets/player/ben.mp3");
        break;
    }
  }

  // Check for collisions.
  for (std::unique_ptr<Projectile>& projectile : projectiles_) {
    int row = projectile->GetPosition().y / kTileHeight;
    int col = projectile->GetPosition().x / kTileWidth;
    if (projectile->CheckCollision(kScreenWidth, kScreenHeight) ||
        level_->GetCurrentRoom()->GetTileMap()[row][col]->IsWall()) {
      projectile.reset();
      projectiles_.erase(
          std::find(projectiles_.begin(), projectiles_.end(), projectile));
      return;
    }
  }

  // Handle movement.
  // TODO(@desmondcchi): Check if passing in a function to another function is
  // the proper way of giving another class access to a member function that
  // is owned by said class.
  player_->HandleMovement(kScreenWidth, kScreenHeight,
                          level_->GetCurrentRoom()->GetTileMap(), level_,
                          [this]() { ClearProjectiles(); });

  for (const std::unique_ptr<Projectile>& projectile : projectiles_) {
    projectile->HandleMovement();
  }
}

void Game::Update() {
  player_->Update();
  for (const std::unique_ptr<Projectile>& projectile : projectiles_) {
    projectile->Update();
  }
}

void Game::Render() {
  // Set background to be black.
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);

  // Render level tile map.
  level_->GetCurrentRoom()->Render();

  for (const std::unique_ptr<Projectile>& projectile : projectiles_) {
    projectile->Render();
  }

  player_->Render();

  SDL_RenderPresent(renderer_);
}

bool Game::IsRunning() const { return is_running_; }

void Game::ClearProjectiles() {
  for (std::unique_ptr<Projectile>& projectile : projectiles_) {
    projectile.reset();
  }
  projectiles_.clear();
}

}  // namespace game
