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

  rect_ = new SDL_FRect(SDL_FRect{
      .x = static_cast<float>(x),
      .y = static_cast<float>(y),
      .w = static_cast<float>(width),
      .h = static_cast<float>(height),
  });
}

int Tile::GetWidth() const { return width_; }

int Tile::GetHeight() const { return height_; }

SDL_FRect* Tile::GetRect() const { return rect_; }

bool Tile::IsWall() const { return is_wall_; }

void Tile::Render() { SDL_RenderCopyF(renderer_, texture_, NULL, rect_); }

bool IsCharWall(char c) {
  // Add chars that represent a wall block that has collision.
  absl::flat_hash_set<char> wall_chars = {'0'};

  return wall_chars.contains(c);
}

}  // namespace level
