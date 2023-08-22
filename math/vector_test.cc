#include "math/vector.h"

#include "gtest/gtest.h"

namespace math {
namespace {

TEST(VectorTest, CoordinateConstructor) {
  Vector vector(SDL_FPoint{1.0f, 2.3f}, SDL_FPoint{4.5f, 10.0f});

  EXPECT_NEAR(vector.position_.x, 3.5f, 0.01f);
  EXPECT_NEAR(vector.position_.y, 7.7f, 0.01f);
  EXPECT_NEAR(vector.magnitude_, 8.45f, 0.01f);
}

TEST(VectorTest, Constructor) {
  Vector vector(2.5f, -3.9f);

  EXPECT_NEAR(vector.position_.x, 2.5f, 0.01f);
  EXPECT_NEAR(vector.position_.y, -3.9f, 0.01f);
  EXPECT_NEAR(vector.magnitude_, 4.63f, 0.01f);
}

TEST(VectorTest, CopyConstructor) {
  Vector vector_a(3.2f, 2.6f);
  Vector vector_b(vector_a);

  EXPECT_NEAR(vector_a.position_.x, vector_b.position_.x, 0.01f);
  EXPECT_NEAR(vector_a.position_.y, vector_b.position_.y, 0.01f);
}

TEST(VectorTest, MoveConstructor) {
  Vector vector(Vector(3.2f, 1.2f));

  EXPECT_NEAR(vector.position_.x, 3.2f, 0.01f);
  EXPECT_NEAR(vector.position_.y, 1.2f, 0.01f);
}

TEST(VectorTest, AssignmentOperator) {
  Vector vector_a(3.2f, 2.1f);
  Vector vector_b = vector_a;

  EXPECT_NEAR(vector_a.position_.x, vector_b.position_.x, 0.01f);
  EXPECT_NEAR(vector_a.position_.y, vector_b.position_.y, 0.01f);
}

TEST(VectorTest, Equivalence) {
  Vector vector_a(2.0f, 2.1f);
  Vector vector_b(2.0f, 2.1f);

  EXPECT_TRUE(vector_a == vector_b);
}

TEST(VectorTest, Addition) {
  Vector vector_a(1.2f, 2.5f);
  Vector vector_b(2.3f, -2.3f);

  EXPECT_NEAR((vector_a + vector_b).position_.x, 3.5f, 0.01f);
  EXPECT_NEAR((vector_a + vector_b).position_.y, 0.2f, 0.01f);
}

TEST(VectorTest, AdditionAssignment) {
  Vector vector_a(1.2f, 2.5f);
  Vector vector_b(2.3f, -2.3f);

  vector_a += vector_b;
  EXPECT_NEAR(vector_a.position_.x, 3.5f, 0.01f);
  EXPECT_NEAR(vector_a.position_.y, 0.2f, 0.01f);
}

TEST(VectorTest, Subtraction) {
  Vector vector_a(1.2f, 2.5f);
  Vector vector_b(2.3f, -2.3f);

  EXPECT_NEAR((vector_a - vector_b).position_.x, -1.1f, 0.01f);
  EXPECT_NEAR((vector_a - vector_b).position_.y, 4.8f, 0.01f);
}

TEST(VectorTest, SubtractionAssignment) {
  Vector vector_a(1.2f, 2.5f);
  Vector vector_b(2.3f, -2.3f);

  vector_a -= vector_b;

  EXPECT_NEAR(vector_a.position_.x, -1.1f, 0.01f);
  EXPECT_NEAR(vector_a.position_.y, 4.8f, 0.01f);
}

TEST(VectorTest, DotProduct) {
  Vector vector_a(2.5f, 3.0f);
  Vector vector_b(2.0f, 2.0f);

  EXPECT_NEAR(DotProduct(vector_a, vector_b), 11.0f, 0.01f);
}

TEST(VectorTest, DotProductOperator) {
  Vector vector_a(2.5f, 3.0f);
  Vector vector_b(2.0f, 2.0f);

  EXPECT_NEAR(vector_a * vector_b, 11.0f, 0.01f);
}

TEST(VectorTest, CrossProduct) {
  Vector vector_a(2.2f, 1.5f);
  Vector vector_b(2.0f, 2.0f);

  EXPECT_NEAR(CrossProduct(vector_a, vector_b), 1.4f, 0.01f);
}

TEST(VectorTest, Division) {
  Vector vector(5.0f, 2.5f);
  Vector result = vector / 2.0f;

  EXPECT_NEAR(result.position_.x, 2.5f, 0.01f);
  EXPECT_NEAR(result.position_.y, 1.25f, 0.01f);
}

TEST(VectorTest, UnitVector) {
  Vector vector(2.0f, 3.0f);
  Vector unit_vector = vector.GetUnitVector();

  EXPECT_NEAR(unit_vector.position_.x, 2.0f / std::sqrt(13), 0.01f);
  EXPECT_NEAR(unit_vector.position_.y, 3.0f / std::sqrt(13), 0.01f);
}

TEST(VectorTest, ComputeMagnitude) {
  Vector vector(0.0f, 0.0f);
  vector += Vector(1.0f, 0.0f);

  EXPECT_NEAR(vector.magnitude_, 1.0f, 0.01f)
      << "x: " << vector.position_.x << "\n"
      << "y: " << vector.position_.y << "\n"
      << "magnitude: " << vector.magnitude_ << "\n";
}

}  // namespace
}  // namespace math
