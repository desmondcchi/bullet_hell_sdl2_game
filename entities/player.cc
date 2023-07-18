#include "entities/player.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace entities {

Player::Player(SDL_Renderer* renderer) {
  renderer_ = renderer;

  x_pos_ = 0;
  y_pos_ = 0;
  width_ = 25;
  height_ = 25;
  speed_ = 5;
  id_ = GenerateID();

  UpdateRect();
}

void Player::Update() {
  UpdateRect();
}

void Player::Render() {
  SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
  SDL_RenderFillRect(renderer_, GetRect());
}

int Player::GenerateID() const {
  static int id = 0;
  return ++id;
}

SDL_Rect* Player::GetRect() { return &rect_; }

void Player::Move(Direction dir) {
  switch (dir) {
    case Direction::kUp:
      y_pos_ -= speed_;
      break;
    case Direction::kDown:
      y_pos_ += speed_;
      break;
    case Direction::kLeft:
      x_pos_ -= speed_;
      break;
    case Direction::kRight:
      x_pos_ += speed_;
      break;
    default:
      break;
  }
}

void Player::UpdateRect() {
  rect_.x = x_pos_;
  rect_.y = y_pos_;
  rect_.w = width_;
  rect_.h = height_;
}

}  // namespace entities
