#ifndef PROJECTILES_CARROT_GUN_PROJECTILE_
#define PROJECTILES_CARROT_GUN_PROJECTILE_

#include "math/vector.h"
#include "projectiles/projectile.h"
#include "SDL2/SDL.h"

namespace projectiles {

class CarrotGunProjectile : public Projectile {
 public:
  CarrotGunProjectile(SDL_FPoint start_position,
                      SDL_FPoint end_position, SDL_Renderer* renderer);
  CarrotGunProjectile(const CarrotGunProjectile& projectile) = default;
  CarrotGunProjectile& operator=(const CarrotGunProjectile& projectile) =
      default;
  CarrotGunProjectile(CarrotGunProjectile&& projectile) = default;

  void HandleMovement() override;
  bool CheckCollision(int screen_width, int screen_height) override;
  void Update() override;
  void Render() override;
};

}  // namespace projectiles

#endif
