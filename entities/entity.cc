#include "entities/entity.h"

#include "SDL2/SDL.h"

namespace entities {

SDL_FPoint Entity::GetPosition() const { return position_; }

float Entity::GetWidth() const { return width_; }

float Entity::GetHeight() const { return height_; }

}  // namespace entities
