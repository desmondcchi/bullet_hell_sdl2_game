#include "entities/player.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace entities {

Player::Player(SDL_Renderer* renderer) {
	renderer_ = renderer;

  x_pos_ = 100;
  y_pos_ = 100;
  width_ = 25;
  height_ = 25;
  speed_ = 20;
  id_ = GenerateID();

  rect_.x = x_pos_;
  rect_.y = y_pos_;
  rect_.w = width_;
  rect_.h = height_;
}

void Player::Update() {}

void Player::Render() {
	// TODO(desmondchi): Fix error. SDL_RenderFillRect parameter 1 (renderer_) is invalid.
  SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
  SDL_RenderFillRect(renderer_, GetRect());
}

int Player::GenerateID() const {
  static int id = 0;
  return ++id;
}

SDL_Rect* Player::GetRect() { return &rect_; }

}  // namespace entities
