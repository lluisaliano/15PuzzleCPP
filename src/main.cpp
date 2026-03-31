#include <iostream>

#include "Board.hpp"
#include "UserInput.hpp"

int main() {
  Board board{};
  std::cout << board;

  while (true) {
    auto command{UserInput::getCommand()};
    auto direction{UserInput::getDirectionFromCommand(command)};
    board.moveTile(direction);
    std::cout << board;
  }

  return 0;
}
