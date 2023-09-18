#include "projectiles/carrot_gun_projectile.h"

#include "SDL2/SDL.h"
#include "math/vector.h"

namespace projectiles {

CarrotGunProjectile::CarrotGunProjectile(SDL_FPoint start_position,
                                         SDL_FPoint end_position,
                                         SDL_Renderer* renderer) {
  renderer_ = renderer;

  width_ = 10.0f;
  height_ = 10.0f;
  position_ = start_position;
  speed_ = 10.0f;
  direction_ = ComputeDirection(start_position, end_position);
  rect_ = new SDL_FRect(SDL_FRect{
      .x = position_.x,
      .y = position_.y,
      .w = width_,
      .h = height_,
  });
}

void CarrotGunProjectile::HandleMovement() {
  position_.x += direction_.position_.x * speed_;
  position_.y += direction_.position_.y * speed_;
}

bool CarrotGunProjectile::CheckCollision(int screen_width, int screen_height) {
  if (position_.x >= screen_width - width_ || position_.x <= 0) {
    return true;
  }
  if (position_.y >= screen_height - height_ || position_.y <= 0) {
    return true;
  }

  return false;
}

void CarrotGunProjectile::Update() {
  rect_->x = position_.x;
  rect_->y = position_.y;
  rect_->w = width_;
  rect_->h = height_;
}

void CarrotGunProjectile::Render() {
  SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
  SDL_RenderFillRectF(renderer_, rect_);
}

}  // namespace projectiles
