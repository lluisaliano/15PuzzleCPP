#include "Direction.hpp"

class Point {
 private:
  int m_x{0};
  int m_y{0};

  void checkPointExistence();

 public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  bool operator==(const Point&) const = default;
  Point getAdjacentPoint(const Direction& direction) const;
};
