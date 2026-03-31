#include <iostream>

#include "Board.hpp"
#include "Direction.hpp"
#include "UserInput.hpp"

#include "Point.hpp"
// int main() {
//   Board board{};
//   std::cout << board;

//   for (int i{0}; i < 4; ++i) {
//     std::cout << "Generating Random Direction... " << Direction::getRandom() << '\n';
//   }

//   while (true) {
//     auto command{UserInput::getCommand()};
//     auto direction{UserInput::getDirectionFromCommand(command)};
//     std::cout << "You entered direction: " << direction << '\n';
//   }

//   return 0;
// }

// Note: save your main() from the prior step, as you'll need it again in the next step
int main()
{
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up)    == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down)  == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left)  == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

    return 0;
}
