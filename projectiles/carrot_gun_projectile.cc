#include "projectiles/carrot_gun_projectile.h"

namespace projectiles {

CarrotGunProjectile::CarrotGunProjectile(int x_pos, int y_pos, int cursor_x,
                                         int cursor_y, SDL_Renderer* renderer) {
  renderer_ = renderer;

  width_ = 5;
  height_ = 5;
  x_pos_ = x_pos;
  y_pos_ = y_pos;
  speed_ = 10;
}

void CarrotGunProjectile::HandleMovement() {}

void CarrotGunProjectile::Update() {}

void CarrotGunProjectile::Render() {}

}  // namespace projectiles
