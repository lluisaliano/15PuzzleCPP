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

    if (command == UserInput::Commands::quit) {
      UserOutput::printCenteredMessage("Bye!");
      return 0;
    }

    auto direction{UserInput::getDirectionFromCommand(command)};
    auto result{board.moveTile(direction)};
    // Avoid printing the board when doing a wrong movement
    if (!result) {
      constexpr std::string_view message{"This movement is not possible\n"};
      UserOutput::printHorizontalSpace(message.size());
      std::cout << message << '\n';
      continue;
    }
    UserOutput::clearScreen();
    std::cout << board;

    if (board.isSolved()) {
      UserOutput::printCenteredMessage("You won!");
      return 0;
    }
  }

  return 0;
}
