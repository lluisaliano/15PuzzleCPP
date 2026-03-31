#include <iostream>

#include "Board.hpp"
#include "UserInput.hpp"
#include "UserOutput.hpp"

int main() {
  UserOutput::clearScreen();
  Board board{};
  board.randomizeBoard();
  std::cout << board;

  while (true) {
    auto command{UserInput::getCommand()};
    auto direction{UserInput::getDirectionFromCommand(command)};
    auto result{board.moveTile(direction)};
    // Avoid printing the board when doing a wrong movement
    if (!result) {
      std::cout << "This movement is not possible\n";
      continue;
    }
    UserOutput::clearScreen();
    std::cout << board;

    if (board.isSolved()) {
      std::cout << "\n\nYou won!\n\n";
      return 0;
    }
  }

  return 0;
}
