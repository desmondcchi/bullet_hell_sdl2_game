#ifndef LEVEL_LEVEL_H_
#define LEVEL_LEVEL_H_

#include <memory>
#include <vector>

#include "SDL2/SDL.h"
#include "absl/strings/string_view.h"
#include "proto/level.pb.h"
#include "level/room.h"

namespace level {

class Level {
 public:
  Level(absl::string_view tile_sheet_path, absl::string_view level_txt_path);

  // "Teleport" to room (not restricted by adjacent rooms), given room index.
  void GoToRoom(int room_number);

  enum RoomDirection { kLeft, kRight, kUp, kDown };
  // Move to a room that is left, right, up, or down, if possible.
  void Move(RoomDirection dir);

 private:
  LevelGraph* level_;

  // Pointer to current room.
  std::unique_ptr<Room> room_;
  std::vector<std::unique_ptr<Room>> rooms_;

  // Parses through the text file and loads the level graph.
  void LoadLevel(absl::string_view level_txt_path);
};

}  // namespace level

#endif
