#pragma once
#include <array>
#include <ostream>

#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"

class Board {
 private:
  std::array<Tile, 16> m_board{};

  bool pointExists(const Point&);
  bool pointIsValid(const Point&, const Direction&);

 public:
  Board();

  int static constexpr cols{4};
  int static constexpr rows{4};

  bool moveTile(const Direction&);

  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
