#include <iostream>

#include "Direction.hpp"

Direction::Direction(Direction::Directions direction) {
  m_direction = direction;
}

Direction Direction::operator-() {
  switch (this->m_direction) {
    case up:
      return Direction(down);
    case left:
      return Direction(right);
    case down:
      return Direction(up);
    case right:
      return Direction(left);
    default:
      std::cout << "Direction does not exist" << '\n';
      std::exit(1);
  }
}

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
  std::string_view name{Direction::s_names[direction.m_direction]};
  out << name;
  return out;
}
