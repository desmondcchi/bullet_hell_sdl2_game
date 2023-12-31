#include "level/room.h"

#include <memory>

#include "SDL2/SDL.h"
#include "absl/container/flat_hash_map.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "proto/level.pb.h"

namespace level {
namespace {

using ::testing::ContainerEq;
using ::testing::Test;

class RoomTest : public Test {
 protected:
  SDL_Renderer* renderer_ =
      SDL_CreateRenderer(SDL_CreateWindow("Test", 0, 0, 0, 0, 0), 1, 0);
};

TEST_F(RoomTest, LoadTileDict) {
  std::unique_ptr<Room> room = std::make_unique<Room>(
      "level/testdata/tiles/", "level/testdata/room_tile_map.txt", RoomNode(),
      16, 24, 1200, 800, renderer_);
  absl::flat_hash_map<char, std::string> tile_dict = room->GetTileDict();

  EXPECT_EQ(tile_dict.size(), 2);

  absl::flat_hash_map<char, std::string> expected_tile_dict = {
      {'0', "level/testdata/tiles/0.png"},
      {'1', "level/testdata/tiles/1.png"},
  };
  EXPECT_THAT(tile_dict, ContainerEq(expected_tile_dict));
}

// TODO(@LucasDil): Write unit test for LoadTileMap().
// TEST_F(RoomTest, LoadTileMap) {
//
// }

}  // namespace
}  // namespace level
