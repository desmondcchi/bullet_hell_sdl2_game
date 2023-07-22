#include "math/vector.h"

#include <cmath>
#include <memory>

#include "math/coordinate.h"

namespace math {

Vector::Vector(Coordinate start, Coordinate end) {
  x_ = end.x - start.x;
  y_ = end.y - start.y;
  magnitude_ = ComputeMagnitude(x_, y_);
}

Vector::Vector(float x, float y) {
  x_ = x;
  y_ = y;
  magnitude_ = ComputeMagnitude(x, y);
}

Vector Vector::operator+(const Vector& vector) const {
  return Vector(x_ + vector.x_, y_ + vector.y_);
}

Vector Vector::operator-(const Vector& vector) const {
  return Vector(x_ - vector.x_, y_ - vector.y_);
}

Vector Vector::operator/(float num) const {
  return Vector(x_ / num, y_ / num);
}

bool Vector::operator==(const Vector& vector) const {
  return x_ == vector.x_ && y_ == vector.y_ && magnitude_ == vector.magnitude_;
}

// Dot Product
float Vector::operator*(const Vector& vector) const {
  return x_ * vector.x_ + y_ * vector.y_;
}

float DotProduct(const Vector& vector_a, const Vector& vector_b) {
  return vector_a.x_ * vector_b.x_ + vector_a.y_ * vector_b.y_;
}

float CrossProduct(const Vector& vector_a,
                           const Vector& vector_b) {
  return vector_a.x_ * vector_b.y_ - vector_a.y_ * vector_b.x_;
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
