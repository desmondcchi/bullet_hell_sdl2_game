#ifndef MATH_COORDINATE_H_
#define MATH_COORDINATE_H_

namespace math {

struct Coordinate {
  Coordinate(float x, float y) : x(x), y(y) {};
  float x;
  float y;
};

}  // namespace math

#endif
