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

void Board::moveTile(const Direction& direction) {
  auto it{std::ranges::find(m_board, Tile(0))};
  int emptyTileIndex{static_cast<int>(std::distance(m_board.begin(), it))};

  // Compute row and column from row major indexing
  int row{emptyTileIndex / rows};
  int col{emptyTileIndex % cols};

  Point p{row, col};

  // Get point in the opposite direction
  Point adjacentPoint{p.getAdjacentPoint(-direction)};
  if (!pointExists(adjacentPoint)) {
    std::cerr << "This Tile does not exist\n";
  }

  // FIX: This indexing allows jumps at the end and begining of rows
  int newTileIndex{adjacentPoint.getY() + adjacentPoint.getX() * cols};

  std::swap(m_board[static_cast<std::size_t>(newTileIndex)],
            m_board[static_cast<std::size_t>(emptyTileIndex)]);
}

bool Board::pointExists(const Point& point) {
  auto x{point.getX()};
  auto y{point.getY()};
  if (x < 0 || x > rows - 1 || y < 0 || y > cols - 1) {
    return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
  for (int i{0}; i < g_consoleLines; ++i) {
    out << '\n';
  }

  for (int i{0}; i < board.cols; ++i) {
    for (int j{0}; j < board.rows; ++j) {
      out << board.m_board[static_cast<std::size_t>(j + i * board.cols)];
    }
    out << '\n';
  }

  return out;
}
