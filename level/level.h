#ifndef LEVEL_LEVEL_H_
#define LEVEL_LEVEL_H_

#include <memory>
#include <vector>

#include "SDL2/SDL.h"
#include "absl/strings/string_view.h"
#include "level/room.h"
#include "proto/level.pb.h"

namespace level {

class Level {
 public:
  Level(absl::string_view tile_dir_path, absl::string_view level_txt_path,
        SDL_Renderer* renderer);

  // "Teleport" to room (not restricted by adjacent rooms), given room index.
  void GoToRoom(int room_number);

  enum RoomDirection { kLeft, kRight, kUp, kDown };
  // Move to a room that is left, right, up, or down, if possible. If not,
  // return false.
  bool Move(RoomDirection dir);

  // Returns how many rooms there are in the level.
  int GetRoomsSize() const;

  // Returns a unique pointer to the current room.
  std::shared_ptr<Room> GetCurrentRoom() const;

  // Returns a unique ptr to the room specified via index.
  std::shared_ptr<Room> GetRoomAt(int index) const;

 private:
  LevelGraph level_;

  SDL_Renderer* renderer_ = nullptr;

  // Pointer to current room.
  std::shared_ptr<Room> current_room_;
  std::vector<std::shared_ptr<Room>> rooms_;

  // Parses through the text file and loads the level graph.
  void LoadLevel(absl::string_view level_txt_path,
                 absl::string_view tile_dir_path);
};

}  // namespace level

#endif
