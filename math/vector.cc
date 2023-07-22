#include "math/vector.h"

#include <cmath>
#include <memory>

#include "SDL2/SDL.h"

namespace math {

Vector::Vector(SDL_FPoint start, SDL_FPoint end) {
  position_.x = end.x - start.x;
  position_.y = end.y - start.y;
  magnitude_ = ComputeMagnitude(position_.x, position_.y);
}

Vector::Vector(float x, float y) {
  position_.x = x;
  position_.y = y;
  magnitude_ = ComputeMagnitude(x, y);
}

Vector Vector::operator+(const Vector& vector) const {
  return Vector(position_.x + vector.position_.x,
                position_.y + vector.position_.y);
}

Vector Vector::operator-(const Vector& vector) const {
  return Vector(position_.x - vector.position_.x,
                position_.y - vector.position_.y);
}

Vector Vector::operator/(float num) const { return Vector(position_.x / num, position_.y / num); }

bool Vector::operator==(const Vector& vector) const {
  return position_.x == vector.position_.x && position_.y == vector.position_.y && magnitude_ == vector.magnitude_;
}

// Dot Product
float Vector::operator*(const Vector& vector) const {
  return position_.x * vector.position_.x + position_.y * vector.position_.y;
}

float DotProduct(const Vector& vector_a, const Vector& vector_b) {
  return vector_a.position_.x * vector_b.position_.x + vector_a.position_.y * vector_b.position_.y;
}

float CrossProduct(const Vector& vector_a, const Vector& vector_b) {
  return vector_a.position_.x * vector_b.position_.y - vector_a.position_.y * vector_b.position_.x;
}

Vector Vector::GetUnitVector() const {
  /*
  Normalization Formula:
          Unit Vector = Vector / ||Vector|| <- Magnitude
  */

  return *this / magnitude_;
}

float Vector::ComputeMagnitude(float x, float y) {
  return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

}  // namespace math
