#include "level/level.h"

#include <memory>
#include <utility>

#include "SDL2/SDL.h"
#include "absl/log/check.h"
#include "absl/strings/string_view.h"
#include "level/room.h"
#include "util/proto.h"

namespace level {

Level::Level(absl::string_view tile_dir_path, absl::string_view level_txt_path,
             int num_rows, int num_cols, int screen_width, int screen_height,
             SDL_Renderer* renderer) {
  CHECK_EQ(renderer != nullptr, true) << "Renderer is nullptr.";
  renderer_ = renderer;
  LoadLevel(level_txt_path, tile_dir_path, num_rows, num_cols, screen_width,
            screen_height);
}

void Level::LoadLevel(absl::string_view level_txt_path,
                      absl::string_view tile_dir_path, int num_rows,
                      int num_cols, int screen_width, int screen_height) {
  util::proto::ReadTextProto(&level_, level_txt_path);

  CHECK_EQ(renderer_ != nullptr, true) << "Renderer is nullptr.";
  // Builds the level graph by creating list of nodes that are indexable.
  for (const RoomNode& room_node : level_.rooms()) {
    rooms_.push_back(std::make_shared<Room>(
        tile_dir_path, room_node.tile_map_path(), room_node, num_rows, num_cols,
        screen_width, screen_height, renderer_));
  }

  // Make current room the room where index = 0.
  CHECK_EQ(rooms_.empty(), false) << "No rooms in level.";
  current_room_ = rooms_[0];
}

int Level::GetRoomsSize() const { return rooms_.size(); }

std::shared_ptr<Room> Level::GetCurrentRoom() const {
  CHECK_NE(current_room_, nullptr) << "current_room_ is nullptr.";
  return current_room_;
}

std::shared_ptr<Room> Level::GetRoomAt(int index) const {
  CHECK(index < rooms_.size());
  return rooms_[index];
}

void Level::GoToRoom(int room_number) {
  CHECK_LT(room_number, level_.rooms_size()) << "Room index out of bound.";
  current_room_ = rooms_[room_number];
}

bool Level::Move(RoomDirection dir) {
  bool success = false;
  int left = current_room_->GetLeft();
  int right = current_room_->GetRight();
  int up = current_room_->GetUp();
  int down = current_room_->GetDown();

  switch (dir) {
    case kLeft:
      if (left != -1) {
        GoToRoom(left);
        success = true;
      }
      break;
    case kRight:
      if (right != -1) {
        GoToRoom(right);
        success = true;
      }
      break;
    case kUp:
      if (up != -1) {
        GoToRoom(up);
        success = true;
      }
      break;
    case kDown:
      if (down != -1) {
        GoToRoom(down);
        success = true;
      }
      break;
  }

  CHECK(success) << "Error: Room does not exist.";
  return success;
}

}  // namespace level
