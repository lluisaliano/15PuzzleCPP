#pragma once
#include <array>
#include <ostream>

#include "Direction.hpp"
#include "Tile.hpp"
#include "Point.hpp"

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

class Board {
 private:
  std::array<Tile, 16> m_board{};

  bool pointExists(const Point&);

 public:
  Board();

  int static constexpr cols{4};
  int static constexpr rows{4};

  void moveTile(const Direction&);

  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
