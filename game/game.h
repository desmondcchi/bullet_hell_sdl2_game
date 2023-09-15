#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <memory>
#include <vector>

#include "SDL2/SDL.h"
#include "entities/player.h"
#include "level/level.h"
#include "projectiles/projectile.h"
#include "util/audio_manager.h"

namespace game {

// Game is implemented as a singleton so that there is only one instance.
class Game {
 public:
  // Returns the single instance of the game.
  static Game& GetInstance() {
    static Game game_;
    return game_;
  }

  // Initializes the game. Returns false if initialization fails.
  bool Init();

  // Runs the game loop, which processes inputs, handles events, and renders
  // frames.
  void GameLoop();

  // Frees up memory and deallocates pointers before shutting down the game.
  void Shutdown();

  // Returns whether or not the game is running.
  bool IsRunning() const;

 private:
  Game() = default;
  Game(const Game& game) = delete;
  Game& operator=(const Game& game) = delete;
  ~Game() = default;

  SDL_Renderer* renderer_;
  SDL_Window* window_;
  SDL_Event event_;
  bool is_running_ = false;

  std::unique_ptr<util::AudioManager> audio_manager_;

  entities::Player* player_ = nullptr;
  std::vector<std::unique_ptr<projectiles::Projectile>> projectiles_;

  std::unique_ptr<level::Level> level_ = nullptr;

  // Processes user mouse/keyboard input and events/collisions.
  void HandleEvents();

  // Updates frames and game statistics.
  void Update();

  // Renders frames.
  void Render();
};

}  // namespace game

#endif
