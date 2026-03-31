#include "Point.hpp"

#include "Direction.hpp"

Point Point::getAdjacentPoint(const Direction& direction) const {
  // Copy Point
  Point p{m_x, m_y};
  switch (direction.getDirection()) {
    case Direction::up:
      --p.m_x;
      break;
    case Direction::right:
      ++p.m_y;
      break;
    case Direction::down:
      ++p.m_x;
      break;
    case Direction::left:
      --p.m_y;
      break;
    default:
      break;
  }

  return p;
}
