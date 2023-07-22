#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <memory>

#include "math/coordinate.h"

namespace math {

class Vector {
 public:
  Vector(Coordinate start, Coordinate end);
  Vector(float x, float y);
  Vector(const Vector& vector) = default;
  Vector& operator=(const Vector& vector) = default;
  Vector(Vector&& vector) = default;
  
  Vector operator+(const Vector& vector) const;
  Vector operator-(const Vector& vector) const;
  Vector operator/(float num) const;
  float operator*(const Vector& vector) const; // Dot Product
  bool operator==(const Vector& vector) const;
  

  ~Vector() = default;

  Vector GetUnitVector() const;

  float x_;
  float y_;
  float magnitude_;

 private:
  float ComputeMagnitude(float x, float y);
};

float DotProduct(const Vector& vector_a, const Vector& vector_b);
float CrossProduct(const Vector& vector_a, const Vector& vector_b);

}  // namespace math

#endif
