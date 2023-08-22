#include "level/room.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/strings/string_view.h"
#include "proto/level.pb.h"

namespace level {

Room::Room(RoomNode room_node) {
  left_ = room_node.left();
  right_ = room_node.right();
  up_ = room_node.up();
  down_ = room_node.down();

  LoadMap(room_node.map_path());
}

Room::Room(absl::string_view tile_sheet_path, RoomNode room, int rows, int cols,
           int screen_width, int screen_height, SDL_Renderer* renderer) {}

void Room::Render() {}

}  // namespace level
