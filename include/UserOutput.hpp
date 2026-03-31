#pragma once
#include <sys/ioctl.h>
#include <unistd.h>

#include <iostream>
#include <string>

namespace UserOutput {
  inline std::pair<int, int> getTerminalWidthAndHeight() {
    struct winsize w;
    // Get window size and store it in w
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return {w.ws_col, w.ws_row};
  }

  inline void printHorizontalSpace(std::size_t space = 0) {
    // Calculate padding
    std::size_t padding{
        (static_cast<std::size_t>(getTerminalWidthAndHeight().first) - space) /
        2};

    // Print text with padding
    std::cout << std::string(padding, ' ');
  }

  inline void printVerticalSpace(std::size_t space = 0) {
    std::size_t padding{
        (static_cast<std::size_t>(getTerminalWidthAndHeight().second) - space) /
        2};

    std::cout << std::string(padding, '\n');
  }

  inline void clearScreen() { std::cout << "\033[2J\033[H"; }

  inline void printCenteredMessage(std::string_view message) {
    clearScreen();
    printVerticalSpace(1);
    printHorizontalSpace(message.size());
    std::cout << message << '\n';
    printVerticalSpace(1);
  }
}  // namespace UserOutput
