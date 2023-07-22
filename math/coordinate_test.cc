#include "math/coordinate.h"

#include "gtest/gtest.h"

namespace math {
namespace {

TEST(CoordinateTest, StructConstructor) {
  Coordinate coordinate(5.1, 2.3);

  EXPECT_NEAR(coordinate.x, 5.1, 0.01);
  EXPECT_NEAR(coordinate.y, 2.3, 0.01);
}

TEST(CoordinateTest, CopyConstructor) {
  Coordinate coordinate_a(3.1, -2.3);
  Coordinate coordinate_b(coordinate_a);

  EXPECT_NEAR(coordinate_b.x, 3.1, 0.01);
  EXPECT_NEAR(coordinate_b.y, -2.3, 0.01);
}

TEST(CoordinateTest, MoveConstructor) {
  Coordinate coordinate(Coordinate(6.1, 2.3));

  EXPECT_NEAR(coordinate.x, 6.1, 0.01);
  EXPECT_NEAR(coordinate.y, 2.3, 0.01);
}

}  // namespace
}  // namespace math
