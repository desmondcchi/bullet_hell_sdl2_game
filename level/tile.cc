#include "level/tile.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace level {

Tile::Tile(SDL_Texture* texture, int x, int y, int width, int height,
           SDL_Renderer* renderer) {
  texture_ = texture;
  x_ = x;
  y_ = y;
  width_ = width;
  height_ = height;
  renderer_ = renderer;

  dest_rect_ = new SDL_FRect();
  dest_rect_->x = x;
  dest_rect_->y = y;
  dest_rect_->w = width;
  dest_rect_->h = height;
}

int Tile::GetWidth() const { return width_; }

int Tile::GetHeight() const { return height_; }

void Tile::Render() {
  SDL_RenderCopyF(renderer_, texture_, NULL, dest_rect_);
}

}  // namespace level
