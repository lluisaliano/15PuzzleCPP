#include <iostream>

#include "Board.hpp"
#include "Direction.hpp"
#include "UserInput.hpp"

// Your code goes here

int main() {
  Board board{};
  std::cout << board;

  for (int i{0}; i < 4; ++i) {
    std::cout << "Generating Random Direction... " << Direction::getRandom() << '\n';
  }

  while (true) {
    auto command{UserInput::getCommand()};
    auto direction{UserInput::getDirectionFromCommand(command)};
    std::cout << "You entered direction: " << direction << '\n';
  }

  return 0;
}
