#ifndef LEVEL_ROOM_H_
#define LEVEL_ROOM_H_

#include <memory>
#include <string>

#include "SDL2/SDL.h"
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"
#include "level/tile.h"
#include "proto/level.pb.h"

namespace level {

class Room {
 public:
  Room(SDL_Renderer* renderer);
  Room(Room&& room) = default;
  Room(const RoomNode& room_node, SDL_Renderer* renderer);
  Room(const Room& room);
  Room(const Room* room);
  Room(absl::string_view tile_dir_path, absl::string_view tile_map_path,
       const RoomNode& room = RoomNode(), int num_rows = 0, int num_cols = 0,
       int screen_width = 0, int screen_height = 0,
       SDL_Renderer* renderer = nullptr);

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

  // Get the tile dictionary that maps character to the path of the tile
  // texture.
  absl::flat_hash_map<char, std::string> GetTileDict() const;

 private:
  SDL_Renderer* renderer_ = nullptr;
  SDL_Texture* tile_sheet_ = nullptr;

  int index_ = 0;
  int left_ = -1;
  int right_ = -1;
  int up_ = -1;
  int down_ = -1;

  int num_rows_ = 0;
  int num_cols_ = 0;
  int tile_width_ = 0;
  int tile_height_ = 0;

  absl::flat_hash_map<char, std::string> tile_dict_;
  std::vector<std::vector<std::shared_ptr<Tile>>> tile_map_;

  // Maps each character to the path of the tile texture.
  void LoadTileDict(absl::string_view tile_dir_path);

  // Parses through txt file with room layout and stores it in a 2x2
  // matrix/grid.
  void LoadTileMap(absl::string_view tile_map_path);
};

}  // namespace level

#endif
