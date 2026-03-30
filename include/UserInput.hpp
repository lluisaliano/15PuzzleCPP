#pragma once
#include <iostream>

namespace UserInput {
  enum Commands { up, left, down, right, quit, max_commands };

  inline Commands getCommand() {
    char commandChar{};

    while (true) {
      std::cin >> commandChar;
      switch (commandChar) {
        case 'w':
          std::cout << "Valid Command: " << 'w' << '\n';
          return Commands::up;
        case 'a':
          std::cout << "Valid Command: " << 'a' << '\n';
          return Commands::left;
        case 's':
          std::cout << "Valid Command: " << 's' << '\n';
          return Commands::down;
        case 'd':
          std::cout << "Valid Command: " << 'd' << '\n';
          return Commands::right;
        case 'q':
          std::cout << "Valid Command: " << 'q' << '\n';
          std::cout << "\n\nBye!\n\n";
          std::exit(0);
      }
    }
  }
}  // namespace UserInput
