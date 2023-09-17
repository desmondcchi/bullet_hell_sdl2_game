#include "level/tile.h"

#include <iostream>

#include "SDL2/SDL.h"
#include "absl/container/flat_hash_set.h"

namespace level {

Tile::Tile(SDL_Texture* texture, int x, int y, int width, int height,
           bool is_wall, SDL_Renderer* renderer) {
  texture_ = texture;
  x_ = x;
  y_ = y;
  width_ = width;
  height_ = height;
  is_wall_ = is_wall;

  renderer_ = renderer;

  dest_rect_ = new SDL_FRect();
  dest_rect_->x = x;
  dest_rect_->y = y;
  dest_rect_->w = width;
  dest_rect_->h = height;
}

int Tile::GetWidth() const { return width_; }

int Tile::GetHeight() const { return height_; }

bool Tile::IsWall() const { return is_wall_; }

void Tile::Render() { SDL_RenderCopyF(renderer_, texture_, NULL, dest_rect_); }

bool IsCharWall(char c) {
  // Add chars that represent a wall block that has collision.
  absl::flat_hash_set<char> wall_chars = {'0'};

  return wall_chars.contains(c);
}

}  // namespace level
