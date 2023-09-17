#ifndef ENTITIES_PLAYER_H_
#define ENTITIES_PLAYER_H_

#include <memory>

#include "SDL2/SDL.h"
#include "entities/entity.h"
#include "level/tile.h"

namespace entities {

class Player : public Entity {
 public:
  Player(float x, float y, int width, int height, int speed,
         SDL_Renderer* renderer);
  Player(const Player& player) = default;
  Player& operator=(const Player& player) = default;
  ~Player() = default;

  // Handles player movement and checks collision with walls.
  void HandleMovement(
      int screen_width, int screen_height,
      const std::vector<std::vector<std::shared_ptr<level::Tile>>>& tile_map);

  // Returns true if player will collide with wall given a position.
  bool CheckWallCollision(
      float x, float y,
      const std::vector<std::vector<std::shared_ptr<level::Tile>>>& tile_map)
      const;

  void Update() override;
  void Render() override;

 private:
  // Update the position and dimensions of the SDL_Rect.
  void UpdateRect();
};

}  // namespace entities

#endif
