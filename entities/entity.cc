#include "entities/entity.h"

#include "SDL2/SDL.h"

namespace entities {

SDL_FPoint Entity::GetPosition() const { return position_; }

float Entity::GetWidth() const { return width_; }

float Entity::GetHeight() const { return height_; }

void Entity::SetPosition(int x, int y) {
  position_.x = x;
  position_.y = y;
}

}  // namespace entities
