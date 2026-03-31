#include <iostream>

#include "Board.hpp"
#include "UserInput.hpp"

int main() {
  Board board{};
  std::cout << board;

  while (true) {
    auto command{UserInput::getCommand()};
    auto direction{UserInput::getDirectionFromCommand(command)};
    auto result{board.moveTile(direction)};
    // Avoid printing the board when doing a wrong movement
    if (!result) {
      continue;
    }
    UserInput::clearScreen();
    std::cout << board;
  }

  return 0;
}
