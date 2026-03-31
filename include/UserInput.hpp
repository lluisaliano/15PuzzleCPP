#pragma once
#include <termios.h>
#include <unistd.h>

#include <iostream>

#include "Direction.hpp"

namespace UserInput {

  enum Commands { up, left, down, right, quit, max_commands };

  inline char getCharWithoutDelimiterCharacter() {
    termios oldTermios{};
    // Store old termios structure
    tcgetattr(STDIN_FILENO, &oldTermios);

    termios newTermios{oldTermios};

    // Put the terminal in non canonical mode to avoid typing delimiters
    newTermios.c_lflag &= static_cast<tcflag_t>(-ICANON);
    // Put the terminal in ECHO mode, to hide input characters
    newTermios.c_lflag &= static_cast<tcflag_t>(-ECHO);

    // Wait until we have received 1 byte (1 char) with no timeout
    newTermios.c_cc[VMIN] = 1;
    newTermios.c_cc[VTIME] = 0;

    // Apply new changes immediately with TCSANOW
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);

    char ch{};
    std::cin >> ch;

    // Recover old termios structure
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);

    return ch;
  }

  inline Commands getCommand() {
    while (true) {
      char commandChar{getCharWithoutDelimiterCharacter()};
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

  inline void clearScreen() { std::cout << "\033[2J\033[H"; }
}  // namespace UserInput
