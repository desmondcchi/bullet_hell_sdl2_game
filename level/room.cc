#include "level/room.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "proto/level.pb.h"
#include "util/file.h"

namespace level {

Room::Room() {
  index_ = 0;

  left_ = -1;
  right_ = -1;
  up_ = -1;
  down_ = -1;

  num_rows_ = 0;
  num_cols_ = 0;
  tile_width_ = 0;
  tile_height_ = 0;

  LoadTileDict("assets/tiles/");
}

Room::Room(const RoomNode& room_node) {
  index_ = room_node.index();

  left_ = room_node.left();
  right_ = room_node.right();
  up_ = room_node.up();
  down_ = room_node.down();

  // TODO(desmondchi): Uncomment when LoadMap() is defined.
  // LoadMap(room_node.map_path());
}

Room::Room(const Room& room) {
  index_ = room.index_;

  left_ = room.left_;
  right_ = room.right_;
  up_ = room.up_;
  down_ = room.down_;

  num_rows_ = room.num_rows_;
  num_cols_ = room.num_cols_;
  tile_width_ = room.tile_width_;
  tile_height_ = room.tile_height_;

  tiles_ = room.tiles_;
  tile_dict_ = room.tile_dict_;

  for (int r = 0; r < num_rows_; r++) {
    for (int c = 0; c < num_cols_; c++) {
      tile_map_[r][c] = std::make_unique<Tile>(*room.tile_map_[r][c].get());
    }
  }
}

Room::Room(absl::string_view tile_dir_path, const RoomNode& room, int num_rows,
           int num_cols, int screen_width, int screen_height,
           SDL_Renderer* renderer) {
  LoadTileDict(tile_dir_path);
}

void Room::LoadRoom(absl::string_view room_path) {
  for (int r = 0; r < num_rows_; r++) {
    for (int c = 0; c < num_cols_; c++) {
      tile_map_[r][c] = std::make_unique<Tile>();
    }
  }
}

void Room::LoadTileDict(absl::string_view tile_dir_path) {
  std::vector<std::string> all_files =
      util::file::GetAllFilesInDirectory(tile_dir_path);
  for (const std::string& file : all_files) {
    tile_dict_[absl::StripSuffix(file, ".txt").data()[0]] =
        absl::StrCat(tile_dir_path, file);
  }
}

int Room::GetIndex() const { return index_; }

int Room::GetLeft() const { return left_; }

int Room::GetRight() const { return right_; }

int Room::GetUp() const { return up_; }

int Room::GetDown() const { return down_; }

absl::flat_hash_map<char, std::string> Room::GetTileDict() const {
  return tile_dict_;
}

void Room::Render() {}

}  // namespace level
