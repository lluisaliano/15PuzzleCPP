#include "Point.hpp"

#include <iostream>

#include "Direction.hpp"

Point Point::getAdjacentPoint(const Direction& direction) const {
  // Copy Point
  Point p{m_x, m_y};
  switch (direction.getDirection()) {
    case Direction::up:
      --p.m_y;
      break;
    case Direction::right:
      ++p.m_x;
      break;
    case Direction::down:
      ++p.m_y;
      break;
    case Direction::left:
      --p.m_x;
      break;
    default:
      break;
  }

  p.checkPointExistence();
  return p;
}

void Point::checkPointExistence() {
  if (m_x < 0 || m_x > 3 || m_y < 0 || m_y > 3) {
    std::cerr << "This point does not exist\n";
    std::cerr << "Point: " << m_x << ", " << m_y << '\n';
    std::exit(1);
  }
}
