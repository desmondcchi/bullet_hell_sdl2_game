#include "level/level.h"

#include <memory>

#include "SDL2/SDL.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "proto/level.pb.h"
#include "util/proto.h"

namespace level {
namespace {

using ::level::Level;
using ::testing::Test;
using ::util::proto::ReadTextProto;

class LevelTest : public Test {
 protected:
  SDL_Renderer* renderer_ =
      SDL_CreateRenderer(SDL_CreateWindow("Test", 0, 0, 0, 0, 0), 1, 0);
};

TEST_F(LevelTest, LoadLevel) {
  std::unique_ptr<Level> level = std::make_unique<Level>(
      "assets/tiles/", "level/testdata/level_graph.txt", renderer_);

  // Level graph looks like this:
  /*
      2
      |
  0 - 1
  */

  EXPECT_EQ(level->GetRoomsSize(), 3);
  EXPECT_EQ(level->GetRoomAt(0)->GetIndex(), 0);
  EXPECT_EQ(level->GetRoomAt(1)->GetIndex(), 1);
  EXPECT_EQ(level->GetRoomAt(2)->GetIndex(), 2);
}

// TEST(LevelTest, MoveAndGetCurrentRoom) {
//   std::unique_ptr<Level> level = std::make_unique<Level>(
//       "junk/tilesheet/path", "level/testdata/level_graph.txt", nullptr);

//   EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 0);
//   level->Move(Level::RoomDirection::kRight);
//   EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 1);
//   level->Move(Level::RoomDirection::kUp);
//   EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 2);
//   level->Move(Level::RoomDirection::kDown);
//   EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 1);
// }

// TEST(LevelTest, GoToRoom) {
//   // TODO(@LucasDil): Test the GoToRoom() function and check if the current
//   room
//   // pointer gets updated.
// }

// TEST(LevelTest, MoveIntoMissingRoom) {
//   // TODO(@LucasDil): Test the Move() function and check if it returns false
//   // when moving into a non-existent room.
// }

}  // namespace
}  // namespace level
