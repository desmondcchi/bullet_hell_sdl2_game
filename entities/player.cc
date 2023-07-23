#include "entities/player.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace entities {

Player::Player(SDL_Renderer* renderer) {
  renderer_ = renderer;
  texture_ = IMG_LoadTexture(renderer_, "assets/player/ben_forward_face.png");

  position_ = {.x = 0, .y = 0};
  width_ = 100;
  height_ = 100;
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
  SDL_RenderCopyF(renderer_, texture_, NULL, &dest_rect_);
}

int Player::GenerateID() const {
  static int id = 0;
  return ++id;
}

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
  dest_rect_.x = position_.x;
  dest_rect_.y = position_.y;
  dest_rect_.w = width_;
  dest_rect_.h = height_;
}

}  // namespace entities
