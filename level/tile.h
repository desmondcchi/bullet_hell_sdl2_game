#ifndef LEVEL_TILE_H_
#define LEVEL_TILE_H_

#include "SDL2/SDL.h"

namespace level {

class Tile {
 public:
  Tile() = default;

  Tile(SDL_Texture* texture, int x, int y, int width, int height, bool is_wall,
       SDL_Renderer* renderer);

  void Render();

  // Get width.
  int GetWidth() const;

  // Get height.
  int GetHeight() const;

  // Returns true if the tile is a wall (has collision).
  bool IsWall() const;

  // Get the SDL rectangle.
  SDL_FRect* GetRect() const;

 private:
  SDL_Texture* texture_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  SDL_FRect* rect_ = nullptr;
  // x and y position. (Top left corner of texture is starting position)
  int x_ = 0;
  int y_ = 0;
  int width_ = 0;
  int height_ = 0;
  bool is_wall_ = false;
};

// Checks if a char is a wall tile.
bool IsCharWall(char c);

}  // namespace level

#endif
