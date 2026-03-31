#include "Board.hpp"

Board::Board() {
  for (int i{0}; i < 15; ++i) {
    m_board[static_cast<std::size_t>(i)] = Tile(i + 1);
  }
  m_board[15] = Tile(0);
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
