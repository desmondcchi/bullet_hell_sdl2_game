#include "level/room.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/strings/string_view.h"
#include "proto/level.pb.h"

namespace level {

Room::Room() {
  index_ = 0;

  left_ = -1;
  right_ = -1;
  up_ = -1;
  down_ = -1;

  rows_ = 0;
  cols_ = 0;
  tile_width_ = 0;
  tile_height_ = 0;
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

  rows_ = room.rows_;
  cols_ = room.cols_;
  tile_width_ = room.tile_width_;
  tile_height_ = room.tile_height_;

  tiles_ = room.tiles_;
  tile_dict_ = room.tile_dict_;
  map_ = room.map_;
}

Room::Room(absl::string_view tile_sheet_path, RoomNode room, int rows, int cols,
           int screen_width, int screen_height, SDL_Renderer* renderer) {}

void Room::LoadMap(absl::string_view map_path) {}

int Room::GetIndex() const { return index_; }

int Room::GetLeft() const { return left_; }

int Room::GetRight() const { return right_; }

int Room::GetUp() const { return up_; }

int Room::GetDown() const { return down_; }

void Room::Render() {}

}  // namespace level
