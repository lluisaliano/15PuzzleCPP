#pragma once
#include <cstdint>
#include <ostream>

class Tile {
 private:
  enum Number {
    missing_tile,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    eleven,
    twelve,
    thirteen,
    fourteen,
    fifteen,
  };

  Number m_value{};

 public:
  Tile() = default;
  explicit Tile(std::int32_t value) : m_value(static_cast<Number>(value)) {}

  bool isEmpty() const;
  std::int32_t getNum() const;

  bool operator==(const Tile&) const = default;
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);
