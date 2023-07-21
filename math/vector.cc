#include "math/vector.h"

#include <cmath>
#include <memory>

#include "math/coordinate.h"

namespace math {

Vector::Vector(Coordinate start, Coordinate end) {
  x_ = end.x_ - start.x_;
  y_ = end.y_ - start.y_;
  magnitude_ = ComputeMagnitude(x_, y_);
}

Vector::Vector(float x, float y) {
  x_ = x;
  y_ = y;
  magnitude_ = ComputeMagnitude(x, y);
}

Vector Vector::operator+(const Vector& vector) const {
  return Vector(this->x_ + vector.x_, this->y_ + vector.y_);
}

Vector Vector::operator-(const Vector& vector) const {
  return Vector(this->x_ - vector.x_, this->y_ - vector.y_);
}

Vector Vector::operator/(float num) const {
  return Vector(this->x_ / num, this->y_ / num);
}

// Dot Product
float Vector::operator*(const Vector& vector) const {
  return this->x_ * vector.x_ + this->y_ * vector.y_;
}

float Vector::DotProduct(const Vector& vector_a, const Vector& vector_b) const {
  return vector_a.x_ * vector_b.x_ + vector_a.y_ * vector_b.y_;
}

float Vector::CrossProduct(const Vector& vector_a,
                           const Vector& vector_b) const {
  return vector_a.x_ * vector_b.y_ - vector_a.y_ * vector_b.x_;
}

Vector Vector::GetUnitVector() const {
	/*
	Normalization Formula:
		Unit Vector = Vector / |Vector| <- Magnitude
	*/
}

float ComputeMagnitude(float x, float y) {
  return std::sqrt(std::pow(x, 2) + std::pow(x, 2));
}

}  // namespace math
