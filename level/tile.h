#ifndef LEVEL_TILE_H_
#define LEVEL_TILE_H_

#include "SDL2/SDL.h"

namespace level {

class Tile {
 public:
  Tile() = default;

  Tile(SDL_Texture* texture, int x, int y, int ts_x, int ts_y, int width,
       int height, SDL_Renderer* renderer);

  void Render();

 private:
  SDL_Texture* texture = nullptr;
  // x and y position.
  int x_ = 0;
  int y_ = 0;
  // x and y position on tile sheet.
  int ts_x_ = 0;
  int ts_y_ = 0;

  int width_ = 0;
  int height_ = 0;

  SDL_Renderer* renderer_ = nullptr;
};

}  // namespace level

#endif
