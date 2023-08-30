#ifndef LEVEL_ROOM_H_
#define LEVEL_ROOM_H_

#include "SDL2/SDL.h"
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"
#include "level/tile.h"
#include "proto/level.pb.h"

namespace level {

class Room {
 public:
  Room();
  Room(Room&& room) = default;
  Room(const RoomNode& room_node);
  Room(const Room& room);

  Room(absl::string_view tile_sheet_path, RoomNode room, int rows, int cols,
       int screen_width, int screen_height, SDL_Renderer* renderer);

  // Parses through txt file with map layout and stores it in a 2x2 matrix/grid.
  void LoadMap(absl::string_view map_path);

  void Render();

  // Get room index.
  int GetIndex() const;

  // Get room to left.
  int GetLeft() const;

  // Get room to right.
  int GetRight() const;

  // Get room above.
  int GetUp() const;

  // Get room below.
  int GetDown() const;

 private:
  SDL_Renderer* renderer_ = nullptr;
  SDL_Texture* tile_sheet_ = nullptr;

  int index_ = 0;
  int left_ = -1;
  int right_ = -1;
  int up_ = -1;
  int down_ = -1;

  int rows_ = 0;
  int cols_ = 0;
  int tile_width_ = 0;
  int tile_height_ = 0;
  std::vector<Tile> tiles_;
  absl::flat_hash_map<int, SDL_Texture*> tile_dict_;
  std::vector<std::vector<Tile>> map_;
};

}  // namespace level

#endif
