#pragma once
#include <array>
#include <ostream>
#include <string_view>

#include "Random.hpp"

class Direction {
 public:
  enum Directions { up, left, down, right, max_directions };

 private:
  static constexpr std::array<std::string_view, max_directions> s_names{
      "up", "left", "down", "right"};
  Directions m_direction;

 public:
  Direction(Directions);

  Directions getDirection() const { return m_direction; }

  // Return Random Direction
  static Direction getRandom() {
    auto val{Random::distribution<int>(0, max_directions - 1)};

    return Direction{static_cast<Directions>(val)};
  }

  bool operator==(const Direction&) const = default;
  Direction operator-() const;
  friend std::ostream& operator<<(std::ostream&, const Direction&);
};
