#ifndef ENTITIES_PLAYER_H_
#define ENTITIES_PLAYER_H_

#include "SDL2/SDL.h"
#include "entities/entity.h"

namespace entities {

class Player : public Entity {
 public:
  Player(SDL_Renderer* renderer);
  Player(const Player& player) = default;
  Player& operator=(const Player& player) = default;
  ~Player() = default;

  void HandleMovement(int screen_width, int screen_height);
  void Update() override;
  void Render() override;
  int GenerateID() const override;
  SDL_Rect* GetRect() override;

  enum Direction { kNone, kUp, kDown, kLeft, kRight };
  void Move(Direction dir);

 private:
  // Update the position and dimensions of the SDL_Rect.
  void UpdateRect();
};

}  // namespace entities

#endif
