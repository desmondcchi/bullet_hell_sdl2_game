#include "projectiles/projectile.h"

#include "SDL2/SDL.h"
#include "math/vector.h"

namespace projectiles {

using ::math::Vector;

Projectile::~Projectile() { renderer_ = nullptr; }

SDL_FPoint Projectile::GetPosition() const { return position_; }

Vector Projectile::ComputeDirection(SDL_FPoint start_position,
                                    SDL_FPoint end_position) {
  return Vector(start_position, end_position).GetUnitVector();
}

SDL_FRect* Projectile::GetRect() const { return rect_; }

}  // namespace projectiles
