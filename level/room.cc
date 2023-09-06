#include "level/room.h"

#include <fstream>
#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/log/check.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "proto/level.pb.h"
#include "util/file.h"

namespace level {

Room::Room(SDL_Renderer* renderer) {
  index_ = 0;

  left_ = -1;
  right_ = -1;
  up_ = -1;
  down_ = -1;

  num_rows_ = 0;
  num_cols_ = 0;
  tile_width_ = 0;
  tile_height_ = 0;

  CHECK_EQ(renderer != nullptr, true) << "Renderer is nullptr.";
  renderer_ = renderer;
}

Room::Room(const RoomNode& room_node, SDL_Renderer* renderer) {
  index_ = room_node.index();

  left_ = room_node.left();
  right_ = room_node.right();
  up_ = room_node.up();
  down_ = room_node.down();

  CHECK_EQ(renderer != nullptr, true) << "Renderer is nullptr.";
  renderer_ = renderer;
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

  tile_dict_ = room.tile_dict_;

  // Resize tile_map_.
  tile_map_.resize(num_rows_);
  for (int i = 0; i < num_rows_; i++) {
    tile_map_[i].resize(num_cols_);
  }

  for (int r = 0; r < num_rows_; r++) {
    CHECK_LT(r, tile_map_.size()) << "r is greater than number of rows.";
    for (int c = 0; c < num_cols_; c++) {
      CHECK_LT(c, tile_map_[r].size())
          << "c is greater than number of columns.";
      CHECK_NE(tile_map_[r][c], nullptr)
          << "Tile at " << r << " : " << c << " is a nullptr.";
      tile_map_[r][c] = room.tile_map_[r][c];
    }
  }

  CHECK_NE(room.renderer_, nullptr) << "Renderer is nullptr.";
  renderer_ = room.renderer_;
}

Room::Room(const Room* room) {
  index_ = room->index_;

  left_ = room->left_;
  right_ = room->right_;
  up_ = room->up_;
  down_ = room->down_;

  num_rows_ = room->num_rows_;
  num_cols_ = room->num_cols_;
  tile_width_ = room->tile_width_;
  tile_height_ = room->tile_height_;

  tile_dict_ = room->tile_dict_;

  // Resize tile_map_.
  tile_map_.resize(num_rows_);
  for (int i = 0; i < num_rows_; i++) {
    tile_map_[i].resize(num_cols_);
  }

  for (int r = 0; r < num_rows_; r++) {
    CHECK_LT(r, tile_map_.size()) << "r is greater than number of rows.";
    for (int c = 0; c < num_cols_; c++) {
      CHECK_LT(c, tile_map_[r].size())
          << "c is greater than number of columns.";
      CHECK_NE(tile_map_[r][c], nullptr)
          << "Tile at " << r << " : " << c << " is a nullptr.";
      tile_map_[r][c] = room->tile_map_[r][c];
    }
  }

  CHECK_NE(room->renderer_, nullptr) << "Renderer is nullptr.";
  renderer_ = room->renderer_;
}

Room::Room(absl::string_view tile_dir_path, absl::string_view tile_map_path,
           const RoomNode& room, int num_rows, int num_cols, int screen_width,
           int screen_height, SDL_Renderer* renderer) {
  index_ = room.index();

  left_ = room.left();
  right_ = room.right();
  up_ = room.up();
  down_ = room.down();

  num_rows_ = num_rows;
  num_cols_ = num_cols;

  tile_width_ = (num_rows == 0) ? 0 : screen_width / num_cols;
  tile_height_ = (num_cols == 0) ? 0 : screen_height / num_rows;

  CHECK_EQ(renderer != nullptr, true) << "Renderer is nullptr.";
  renderer_ = renderer;

  LoadTileDict(tile_dir_path);
  LoadTileMap(tile_map_path);
}

void Room::LoadTileMap(absl::string_view tile_map_path) {
  CHECK(!tile_map_path.empty()) << "Tile map path is empty!\n";

  std::ifstream input_file;
  input_file.open(tile_map_path);

  CHECK_EQ(input_file.is_open(), true)
      << "Could not open file " << tile_map_path;

  // Resize tile_map_ to have r x c elements.
  tile_map_.resize(num_rows_);
  for (int i = 0; i < num_rows_; i++) {
    tile_map_[i].resize(num_cols_);
  }

  int x = 0;
  int y = 0;
  for (int r = 0; r < num_rows_; r++) {
    for (int c = 0; c < num_cols_; c++) {
      char curr_char;
      input_file.get(curr_char);
      CHECK_NE(curr_char, '\n') << "Line does not have enough characters (< "
                                << num_cols_ << ") in tile map file.";

      const char* texture_path = tile_dict_[curr_char].c_str();
      CHECK_NE(renderer_, nullptr) << "Renderer is nullptr.";
      SDL_Texture* texture = IMG_LoadTexture(renderer_, texture_path);
      CHECK_NE(texture, nullptr)
          << "Failed to load texture: " << SDL_GetError();
      CHECK_LT(r, tile_map_.size()) << "r is greater than number of rows.";
      CHECK_LT(c, tile_map_[r].size())
          << "c is greater than number of columns.";
      tile_map_[r][c] = std::make_shared<Tile>(texture, x, y, tile_width_,
                                               tile_height_, renderer_);
      x += tile_width_;
    }
    // Clear the end line.
    char eof;
    input_file.get(eof);
    CHECK_EQ(eof, '\n') << "Line has too many characters (> "
                               << num_cols_ << ") in tile map file.";
    x = 0;
    y += tile_height_;
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

void Room::Render() {
  for (const std::vector<std::shared_ptr<Tile>>& row : tile_map_) {
    for (const std::shared_ptr<Tile>& tile : row) {
      if (tile != nullptr) {
        tile->Render();
      }
    }
  }
}

}  // namespace level
