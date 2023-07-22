#include "math/vector.h"

#include "gtest/gtest.h"
#include "math/coordinate.h"

namespace math {
namespace {

TEST(VectorTest, CoordinateConstructor) {
  Vector vector(Coordinate(1.0, 2.3), Coordinate(4.5, 10.0));

  EXPECT_NEAR(vector.x_, 3.5, 0.01);
  EXPECT_NEAR(vector.y_, 7.7, 0.01);
  EXPECT_NEAR(vector.magnitude_, 8.45, 0.01);
}

TEST(VectorTest, Constructor) {
  Vector vector(2.5, -3.9);

  EXPECT_NEAR(vector.x_, 2.5, 0.01);
  EXPECT_NEAR(vector.y_, -3.9, 0.01);
  EXPECT_NEAR(vector.magnitude_, 4.63, 0.01);
}

TEST(VectorTest, CopyConstructor) {
  Vector vector_a(3.2, 2.6);
  Vector vector_b(vector_a);

  EXPECT_NEAR(vector_a.x_, vector_b.x_, 0.01);
  EXPECT_NEAR(vector_a.y_, vector_b.y_, 0.01);
}

TEST(VectorTest, MoveConstructor) {
  Vector vector(Vector(3.2, 1.2));

  EXPECT_NEAR(vector.x_, 3.2, 0.01);
  EXPECT_NEAR(vector.y_, 1.2, 0.01);
}

TEST(VectorTest, AssignmentOperator) {
  Vector vector_a(3.2, 2.1);
  Vector vector_b = vector_a;

  EXPECT_NEAR(vector_a.x_, vector_b.x_, 0.01);
  EXPECT_NEAR(vector_a.y_, vector_b.y_, 0.01);
}

TEST(VectorTest, Equivalence) {
  Vector vector_a(2.0, 2.1);
  Vector vector_b(2.0, 2.1);

  EXPECT_TRUE(vector_a == vector_b);
}

TEST(VectorTest, Addition) {
  Vector vector_a(1.2, 2.5);
  Vector vector_b(2.3, -2.3);

  EXPECT_NEAR((vector_a + vector_b).x_, 3.5, 0.01);
  EXPECT_NEAR((vector_a + vector_b).y_, 0.2, 0.01);
}

TEST(VectorTest, Subtraction) {
  Vector vector_a(1.2, 2.5);
  Vector vector_b(2.3, -2.3);

  EXPECT_NEAR((vector_a - vector_b).x_, -1.1, 0.01);
  EXPECT_NEAR((vector_a - vector_b).y_, 4.8, 0.01);
}

TEST(VectorTest, DotProduct) {
  Vector vector_a(2.5, 3.0);
  Vector vector_b(2.0, 2.0);

  EXPECT_NEAR(DotProduct(vector_a, vector_b), 11.0, 0.01);
}

TEST(VectorTest, DotProductOperator) {
  Vector vector_a(2.5, 3.0);
  Vector vector_b(2.0, 2.0);

  EXPECT_NEAR(vector_a * vector_b, 11.0, 0.01);
}

TEST(VectorTest, CrossProduct) {
  Vector vector_a(2.2, 1.5);
  Vector vector_b(2.0, 2.0);

  EXPECT_NEAR(CrossProduct(vector_a, vector_b), 1.4, 0.01);
}

TEST(VectorTest, Division) {
  Vector vector(5.0, 2.5);
  Vector result = vector / 2.0f;

  EXPECT_NEAR(result.x_, 2.5f, 0.01f);
  EXPECT_NEAR(result.y_, 1.25f, 0.01f);
}

TEST(VectorTest, UnitVector) {
  Vector vector(2.0, 3.0);
  Vector unit_vector = vector.GetUnitVector();

  EXPECT_NEAR(unit_vector.x_, 2.0f / std::sqrt(13), 0.01);
  EXPECT_NEAR(unit_vector.y_, 3.0f / std::sqrt(13), 0.01);
}

}  // namespace
}  // namespace math
