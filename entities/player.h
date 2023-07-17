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

  void Update() override;
  void Render() override;
  int GenerateID() const override;
  SDL_Rect* GetRect() override;
};

}  // namespace entities

#endif
