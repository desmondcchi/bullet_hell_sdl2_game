#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <memory>

#include "SDL2/SDL.h"

namespace math {

class Vector {
 public:
  Vector() = default;
  Vector(SDL_FPoint start, SDL_FPoint end);
  Vector(float x, float y);
  Vector(const Vector& vector) = default;
  Vector& operator=(const Vector& vector) = default;
  Vector(Vector&& vector) = default;

  Vector operator+(const Vector& vector) const;
  void operator+=(const Vector& vector);
  Vector operator-(const Vector& vector) const;
  void operator-=(const Vector& vector);
  Vector operator/(float num) const;
  float operator*(const Vector& vector) const;  // Dot Product
  bool operator==(const Vector& vector) const;

  ~Vector() = default;

  Vector GetUnitVector() const;

  SDL_FPoint position_{.x = 0.0f, .y = 0.0f};
  float magnitude_ = 0.0f;

 private:
  float ComputeMagnitude(float x, float y);
};

float DotProduct(const Vector& vector_a, const Vector& vector_b);
float CrossProduct(const Vector& vector_a, const Vector& vector_b);

}  // namespace math

#endif
