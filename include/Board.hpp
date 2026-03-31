#pragma once
#include <array>
#include <ostream>

#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"

class Board {
 private:
 // Using row major indexing
 std::array<Tile, 16> m_board{};

  bool pointExists(const Point&);
  bool pointIsValid(const Point&, const Direction&);

  // Total random movements that will be used to randomize the board
  static constexpr auto s_totalRandomMovements{1000};

 public:
  Board();

  int static constexpr cols{4};
  int static constexpr rows{4};

  // Randomie the board
  void randomizeBoard();
  // Move a tile in the corresponding direction
  bool moveTile(const Direction&);
  // Check if board is solved
  bool isSolved() const;

  // Compare to boards operator. (Will use the operator== overload of std::vector)
  bool operator==(const Board&) const = default;
  friend std::ostream& operator<<(std::ostream& out, const Board& board);
};

// Solved Board to compare
const inline Board solvedBoard{};
