#include "level/level.h"

#include "absl/log/check.h"
#include "absl/strings/string_view.h"
#include "level/room.h"
#include "util/proto.h"

namespace level {

Level::Level(absl::string_view tile_sheet_path,
             absl::string_view level_txt_path) {
  LoadLevel(level_txt_path);
}

void Level::LoadLevel(absl::string_view level_txt_path) {
  util::proto::ReadTextProto(level_, level_txt_path);

  // Builds the level graph by creating list of nodes that are indexable.
  for (const RoomNode& room : *level_->mutable_rooms()) {
    rooms_.emplace_back(std::make_unique<Room>(room));
  }

  // Make current room the room where index = 0.
  CHECK_EQ(rooms_.empty(), false) << "No rooms in level.";
  room_ = std::make_unique<Room>(rooms_.at(0));
}

void Level::GoToRoom(int room_number) {
  CHECK_LT(room_number, level_->rooms_size()) << "Room index out of bound.";
  room_ = std::make_unique<Room>(level_->mutable_rooms()->Mutable(room_number));
}

void Level::Move(RoomDirection dir) {
  bool success = false;

  switch (dir) {
    case kLeft:
      if (room_->left_ != -1) {
        GoToRoom(room_->left_);
        success = true;
      }
      break;
    case kRight:
      if (room_->right_ != -1) {
        GoToRoom(room_->right_);
        success = true;
      }
      break;
    case kUp:
      if (room_->up_ != -1) {
        GoToRoom(room_->up_);
        success = true;
      }
      break;
    case kDown:
      if (room_->down_ != -1) {
        GoToRoom(room_->down_);
        success = true;
      }
      break;
  }

  if (!success) std::cout << "Error: Room does not exist.\n";
}

}  // namespace level
