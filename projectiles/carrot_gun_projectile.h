#ifndef PROJECTILES_CARROT_GUN_PROJECTILE_
#define PROJECTILES_CARROT_GUN_PROJECTILE_

#include "SDL2/SDL.h"
#include "projectiles/projectile.h"

namespace projectiles {

class CarrotGunProjectile : Projectile {
 public:
  CarrotGunProjectile(int x_pos, int y_pos, int cursor_x, int cursor_y,
                      SDL_Renderer* renderer);
  CarrotGunProjectile(const CarrotGunProjectile& projectile) = default;
  CarrotGunProjectile& operator=(const CarrotGunProjectile& projectile) =
      default;
  ~CarrotGunProjectile() = default;

  void HandleMovement() override;
  void Update() override;
  void Render() override;
};

}  // namespace projectiles

#endif
