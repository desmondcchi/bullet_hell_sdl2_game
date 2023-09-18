#ifndef PROJECTILES_PROJECTILE_H_
#define PROJECTILES_PROJECTILE_H_

#include "SDL2/SDL.h"
#include "math/vector.h"

namespace projectiles {

class Projectile {
 public:
  virtual ~Projectile();

  virtual void HandleMovement() = 0;
  virtual bool CheckCollision(int screen_width, int screen_height) = 0;
  virtual void Update() = 0;
  virtual void Render() = 0;

  // Get the SDL rectangle.
  SDL_FRect* GetRect() const;

  SDL_FPoint GetPosition() const;
  // Computes the unit vector for direction.
  math::Vector ComputeDirection(SDL_FPoint start_point, SDL_FPoint end_point);

 protected:
  SDL_Renderer* renderer_;
  SDL_FPoint position_;
  float width_;
  float height_;
  float speed_;
  math::Vector direction_;
  SDL_FRect* rect_;
};

}  // namespace projectiles

#endif
