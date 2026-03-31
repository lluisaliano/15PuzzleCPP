#include "Board.hpp"

#include <algorithm>
#include <iostream>

#include "Direction.hpp"
#include "Point.hpp"

Board::Board() {
  for (int i{0}; i < 15; ++i) {
    m_board[static_cast<std::size_t>(i)] = Tile(i + 1);
  }
  m_board[15] = Tile(0);
}

// Return true if movement was correct
bool Board::moveTile(const Direction& direction) {
  auto it{std::ranges::find(m_board, Tile(0))};
  int emptyTileIndex{static_cast<int>(std::distance(m_board.begin(), it))};

  // Compute row and column from row major indexing
  int row{emptyTileIndex / rows};
  int col{emptyTileIndex % cols};

  Point emptyTilePoint{row, col};

  // Get point in the opposite direction
  Point adjacentPoint{emptyTilePoint.getAdjacentPoint(-direction)};
  if (!pointExists(adjacentPoint)) {
    return false;
  }

  int newTileIndex{adjacentPoint.getY() + adjacentPoint.getX() * cols};

  std::swap(m_board[static_cast<std::size_t>(newTileIndex)],
            m_board[static_cast<std::size_t>(emptyTileIndex)]);

  return true;
}

// As a completly random puzzle may be unsolvable, we will randomize the
// puzzle by getting random valid directions and applying them conitnuously
void Board::randomizeBoard() {
  for (int i{0}; i < s_totalRandomMovements; ++i) {
    Direction randomDirection{Direction::getRandom()};
    // If direction is valid, count it as a normal movement, otherwise don't
    if (moveTile(randomDirection)) {
      continue;
    }
    --i;
  }
}

bool Board::isSolved() const { return (*this == solvedBoard); }

bool Board::pointExists(const Point& point) {
  auto x{point.getX()};
  auto y{point.getY()};
  if (x < 0 || x > rows - 1 || y < 0 || y > cols - 1) {
    return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
  for (int i{0}; i < board.cols; ++i) {
    for (int j{0}; j < board.rows; ++j) {
      out << board.m_board[static_cast<std::size_t>(j + i * board.cols)];
    }
    out << '\n';
  }

  return out;
}
