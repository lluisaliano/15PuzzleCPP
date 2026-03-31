#pragma once
#include <iostream>

#include "Direction.hpp"

namespace UserInput {
  enum Commands { up, left, down, right, quit, max_commands };

  inline Commands getCommand() {
    char commandChar{};

    while (true) {
      std::cin >> commandChar;
      switch (commandChar) {
        case 'w':
          return Commands::up;
        case 'a':
          return Commands::left;
        case 's':
          return Commands::down;
        case 'd':
          return Commands::right;
        // Exit Game
        case 'q':
          std::cout << "Valid Command: " << 'q' << '\n';
          std::cout << "\n\nBye!\n\n";
          std::exit(0);
      }
    }
  }

  inline Direction getDirectionFromCommand(const Commands command) {
    switch (command) {
      case up:
        return Direction(Direction::up);
      case left:
        return Direction(Direction::left);
      case down:
        return Direction(Direction::down);
      case right:
        return Direction(Direction::right);
      default:
        std::cerr << "No valid direction command" << '\n';
        std::exit(1);
    }
  }
}  // namespace UserInput
