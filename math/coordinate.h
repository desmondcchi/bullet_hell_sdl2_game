#ifndef MATH_COORDINATE_H_
#define MATH_COORDINATE_H_

namespace math {

struct Coordinate {
  Coordinate(float x, float y);
  Coordinate(const Coordinate& coord) = default;
  Coordinate& operator=(const Coordinate& coord) = default;
  ~Coordinate() = default;

  float x_;
  float y_;
};

}  // namespace math

#endif
