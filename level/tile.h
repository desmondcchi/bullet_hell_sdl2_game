#ifndef LEVEL_TILE_H_
#define LEVEL_TILE_H_

#include "SDL2/SDL.h"

namespace level {

class Tile {
 public:
  Tile() = default;

  Tile(SDL_Texture* texture, int x, int y, int width, int height,
       SDL_Renderer* renderer);

  void Render();

  // Get width.
  int GetWidth() const;

  // Get Height.
  int GetHeight() const;

 private:
  SDL_Texture* texture_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  SDL_FRect* dest_rect_ = nullptr;
  // x and y position. (Top left corner of texture is starting position)
  int x_ = 0;
  int y_ = 0;
  int width_ = 0;
  int height_ = 0;
};

}  // namespace level

#endif
