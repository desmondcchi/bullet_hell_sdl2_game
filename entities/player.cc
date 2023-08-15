#include "entities/player.h"

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "math/vector.h"

namespace entities {

Player::Player(SDL_Renderer* renderer) {
  renderer_ = renderer;
  texture_ = IMG_LoadTexture(renderer_, "assets/player/ben_forward_face.png");

  position_ = {.x = 0, .y = 0};
  width_ = 100;
  height_ = 100;
  speed_ = 5;

  UpdateRect();
}

void Player::HandleMovement(int screen_width, int screen_height) {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);
  float dir_x = 0.0f;
  float dir_y = 0.0f;

  if (keystate[SDL_SCANCODE_W]) {
    if (position_.y - speed_ >= 0) {
      dir_y += -1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_A]) {
    if (position_.x - speed_ >= 0) {
      dir_x += -1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_S]) {
    if (position_.y + speed_ <= screen_height - height_) {
      dir_y += 1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_D]) {
    if (position_.x + speed_ <= screen_width - width_) {
      dir_x += 1.0f;
    }
  }

  math::Vector dir_vec = math::Vector(dir_x, dir_y).GetUnitVector();
  position_.x += dir_vec.position_.x * speed_;
  position_.y += dir_vec.position_.y * speed_;
}

void Player::Update() { UpdateRect(); }

void Player::Render() {
  SDL_RenderCopyF(renderer_, texture_, NULL, &dest_rect_);
}

void Player::UpdateRect() {
  dest_rect_.x = position_.x;
  dest_rect_.y = position_.y;
  dest_rect_.w = width_;
  dest_rect_.h = height_;
}

}  // namespace entities
