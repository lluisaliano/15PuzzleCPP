#include "Tile.hpp"

bool Tile::isEmpty() const {
  return (m_value == Number::missing_tile) ? true : false;
}

std::int32_t Tile::getNum() const { return static_cast<std::int32_t>(m_value); }

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
  std::string tileString{std::to_string(tile.getNum())};
  if (tileString.size() == 1) {
    tileString = ' ' + tileString;
  }

  out << ' ' << tileString << ' ';

  return out;
}
