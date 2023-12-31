#include "entities/player.h"

#include <functional>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/log/check.h"
#include "level/level.h"
#include "level/tile.h"
#include "math/vector.h"

namespace entities {

using ::level::Level;
using ::level::Tile;

Player::Player(float x, float y, int width, int height, int speed,
               SDL_Renderer* renderer) {
  renderer_ = renderer;
  texture_ = IMG_LoadTexture(renderer_, "assets/player/ben_forward_face.png");

  position_ = {.x = x, .y = y};
  width_ = width;
  height_ = height;
  speed_ = speed;

  UpdateRect();
}

void Player::HandleMovement(
    int screen_width, int screen_height,
    const std::vector<std::vector<std::shared_ptr<Tile>>>& tile_map,
    std::unique_ptr<Level>& level, std::function<void()> clear_projectiles_fn) {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);
  float dir_x = 0.0f;
  float dir_y = 0.0f;
  int before_next_room_offset = 10;
  int after_next_room_offset = 50;

  if (keystate[SDL_SCANCODE_W]) {
    float next_y_position = position_.y - speed_;

    if (position_.y < before_next_room_offset) {
      // Set new position to bottom of screen.
      SetPosition((screen_width - width_) / 2.0f,
                  screen_height - height_ - after_next_room_offset);
      clear_projectiles_fn();
      level->Move(Level::RoomDirection::kUp);
    } else if (next_y_position >= 0 &&
               !CheckWallCollision(position_.x, next_y_position, tile_map) &&
               !CheckWallCollision(position_.x + width_, next_y_position,
                                   tile_map)) {
      dir_y += -1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_A]) {
    float next_x_position = position_.x - speed_;

    if (position_.x < before_next_room_offset) {
      // Set new position to right of screen.
      SetPosition(screen_width - width_ - after_next_room_offset,
                  (screen_height - height_) / 2.0f);
      clear_projectiles_fn();
      level->Move(Level::RoomDirection::kLeft);
    } else if (!CheckWallCollision(next_x_position, position_.y, tile_map) &&
               !CheckWallCollision(next_x_position, position_.y + height_,
                                   tile_map)) {
      dir_x += -1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_S]) {
    float next_y_position = position_.y + speed_;

    if (position_.y > screen_height - height_ - before_next_room_offset) {
      // Set new position to top of screen.
      SetPosition((screen_width - width_) / 2.0f, after_next_room_offset);
      clear_projectiles_fn();
      level->Move(Level::RoomDirection::kDown);
    } else if (!CheckWallCollision(position_.x, next_y_position + height_,
                                   tile_map) &&
               !CheckWallCollision(position_.x + width_,
                                   next_y_position + height_, tile_map)) {
      dir_y += 1.0f;
    }
  }
  if (keystate[SDL_SCANCODE_D]) {
    float next_x_position = position_.x + speed_;

    if (position_.x > screen_width - width_ - before_next_room_offset) {
      // Set new position to left of screen.
      SetPosition(after_next_room_offset, (screen_height - height_) / 2.0f);
      clear_projectiles_fn();
      level->Move(Level::RoomDirection::kRight);
    } else if (!CheckWallCollision(next_x_position + width_, position_.y,
                                   tile_map) &&
               !CheckWallCollision(next_x_position + width_,
                                   position_.y + height_, tile_map)) {
      dir_x += 1.0f;
    }
  }

  math::Vector dir_vec = math::Vector(dir_x, dir_y).GetUnitVector();
  position_.x += dir_vec.position_.x * speed_;
  position_.y += dir_vec.position_.y * speed_;
}

bool Player::CheckWallCollision(
    float x, float y,
    const std::vector<std::vector<std::shared_ptr<Tile>>>& tile_map) const {
  std::shared_ptr<Tile> tile = tile_map[0][0];
  CHECK_NE(tile, nullptr) << "Tile is nullptr.";
  int tile_width = tile->GetWidth();
  int tile_height = tile->GetHeight();
  int row_index = y / tile_width;
  int col_index = x / tile_height;

  return tile_map[row_index][col_index]->IsWall();
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
