#include "level/level.h"

#include <memory>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "proto/level.pb.h"
#include "util/proto.h"

namespace level {
namespace {

using ::level::Level;
using ::util::proto::ReadTextProto;

TEST(LevelTest, LoadLevel) {
  std::unique_ptr<Level> level = std::make_unique<Level>(
      "junk/tilesheet/path", "level/testdata/level_graph.txt");

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

TEST(LevelTest, MoveAndGetCurrentRoom) {
  std::unique_ptr<Level> level = std::make_unique<Level>(
      "junk/tilesheet/path", "level/testdata/level_graph.txt");

  EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 0);
  level->Move(Level::RoomDirection::kRight);
  EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 1);
  level->Move(Level::RoomDirection::kUp);
  EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 2);
  level->Move(Level::RoomDirection::kDown);
  EXPECT_EQ(level->GetCurrentRoom()->GetIndex(), 1);
}

TEST(LevelTest, GoToRoom) {
  // TODO(@LucasDil): Test the GoToRoom() function and check if the current room
  // pointer gets updated.
}

TEST(LevelTest, MoveIntoMissingRoom) {
  // TODO(@LucasDil): Test the Move() function and check if it returns false
  // when moving into a non-existent room.
}

}  // namespace
}  // namespace level
