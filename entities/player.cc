#include "entities/player.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace entities {

Player::Player(SDL_Renderer* renderer) {
  renderer_ = renderer;

  position_ = {.x = 0, .y = 0};
  width_ = 50;
  height_ = 50;
  speed_ = 5;
  id_ = GenerateID();

  UpdateRect();
}

void Player::HandleMovement(int screen_width, int screen_height) {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_W]) {
    if (position_.y - speed_ >= 0) {
      Move(entities::Player::Direction::kUp);
    }
  }
  if (keystate[SDL_SCANCODE_A]) {
    if (position_.x - speed_ >= 0) {
      Move(entities::Player::Direction::kLeft);
    }
  }
  if (keystate[SDL_SCANCODE_S]) {
    if (position_.y + speed_ <= screen_height - height_) {
      Move(entities::Player::Direction::kDown);
    }
  }
  if (keystate[SDL_SCANCODE_D]) {
    if (position_.x + speed_ <= screen_width - width_) {
      Move(entities::Player::Direction::kRight);
    }
  }
}

void Player::Update() { UpdateRect(); }

void Player::Render() {
  SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
  SDL_RenderFillRectF(renderer_, &rect_);
}

int Player::GenerateID() const {
  static int id = 0;
  return ++id;
}

SDL_FRect* Player::GetRect() { return &rect_; }

void Player::Move(Direction dir) {
  switch (dir) {
    case Direction::kUp:
      position_.y -= speed_;
      break;
    case Direction::kDown:
      position_.y += speed_;
      break;
    case Direction::kLeft:
      position_.x -= speed_;
      break;
    case Direction::kRight:
      position_.x += speed_;
      break;
    default:
      break;
  }
}

void Player::UpdateRect() {
  rect_.x = position_.x;
  rect_.y = position_.y;
  rect_.w = width_;
  rect_.h = height_;
}

}  // namespace entities
