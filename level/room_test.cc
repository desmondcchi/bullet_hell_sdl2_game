#include "level/room.h"

#include <memory>

#include "absl/container/flat_hash_map.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "proto/level.pb.h"

namespace level {
namespace {

using ::testing::ContainerEq;

TEST(RoomTest, LoadTileDict) {
  std::unique_ptr<Room> room = std::make_unique<Room>(
      "level/testdata/tiles/", "level/testdata/room_tile_map.txt");
  absl::flat_hash_map<char, std::string> tile_dict = room->GetTileDict();

  EXPECT_EQ(tile_dict.size(), 2);

  absl::flat_hash_map<char, std::string> expected_tile_dict = {
      {'0', "level/testdata/tiles/0.png"},
      {'1', "level/testdata/tiles/1.png"},
  };
  EXPECT_THAT(tile_dict, ContainerEq(expected_tile_dict));
}

// TEST(RoomTest, LoadTileMap) {
//   RoomNode room_node
//   SDL_Renderer* renderer = SDL_CreateRenderer()
//   std::unique_ptr<Room> room = std::make_unique<Room>(
//       "level/testdata/tiles/", "level/testdata/room_tile_map.txt", room_node,
//       16, 23, 1200, 800, nullptr);
// }

}  // namespace
}  // namespace level
