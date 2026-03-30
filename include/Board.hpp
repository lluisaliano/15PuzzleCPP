#pragma once
#include <Tile.hpp>
#include <array>
#include <ostream>

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

class Board {
 private:
  std::array<Tile, 16> m_board{};

 public:
  Board();

  int static constexpr cols{4};
  int static constexpr rows{4};

  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};
