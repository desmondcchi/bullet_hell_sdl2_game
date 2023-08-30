#include "level/level.h"

#include <iostream>
#include <memory>
#include <utility>

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
  util::proto::ReadTextProto(&level_, level_txt_path);

  // Builds the level graph by creating list of nodes that are indexable.
  for (const RoomNode& room_node : level_.rooms()) {
    rooms_.emplace_back(std::make_unique<Room>(room_node));
  }

  // Make current room the room where index = 0.
  CHECK_EQ(rooms_.empty(), false) << "No rooms in level.";
  current_room_ = std::make_unique<Room>(*rooms_[0].get());
}

int Level::GetRoomsSize() const { return rooms_.size(); }

std::unique_ptr<Room> Level::GetCurrentRoom() const {
  return std::make_unique<Room>(*current_room_.get());
}

std::unique_ptr<Room> Level::GetRoomAt(int index) const {
  CHECK(index < rooms_.size());
  return std::make_unique<Room>(*rooms_[index].get());
}

void Level::GoToRoom(int room_number) {
  CHECK_LT(room_number, level_.rooms_size()) << "Room index out of bound.";
  current_room_ = std::make_unique<Room>(level_.rooms().at(room_number));
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
