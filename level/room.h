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
  Room(RoomNode room_node);

  Room(absl::string_view tile_sheet_path, RoomNode room, int rows, int cols,
       int screen_width, int screen_height, SDL_Renderer* renderer);

  void LoadMap(absl::string_view map_path);

  void Render();

  int left_;
  int right_;
  int up_;
  int down_;

 private:
  SDL_Renderer* renderer_;
  SDL_Texture* tile_sheet_;

  int rows_;
  int cols_;
  int tile_width_;
  int tile_height_;
  std::vector<Tile> tiles;
  absl::flat_hash_map<int, SDL_Texture*> tile_dict;
  std::vector<std::vector<Tile>> map_;
};

}  // namespace level

#endif
