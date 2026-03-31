#pragma once

#include "Direction.hpp"

class Point {
 private:
  int m_x{0};
  int m_y{0};

 public:
  // Represent the x,y coordinates (0,0) is on top left
  Point(int x, int y) : m_x{x}, m_y{y} {}

  int getX() const { return m_x; }
  int getY() const { return m_y; }

  bool operator==(const Point&) const = default;
  Point getAdjacentPoint(const Direction& direction) const;
};
