#include <iostream>
#include <Tile.hpp>
#include <Board.hpp>
#include "UserInput.hpp"

// Your code goes here

int main()
{
    Board board{};
    std::cout << board;

    while (true) {
      UserInput::getCommand();
    }

    return 0;
}
