#include <chrono>
#include <random>
#include <type_traits>

namespace Random {
  inline std::mt19937 generate() {
    // Generate seed based on random Time and random Device
    auto timePoint{std::chrono::steady_clock::now()};
    std::random_device rd{};
    std::seed_seq seed{rd(),
                       rd(),
                       rd(),
                       rd(),
                       rd(),
                       rd(),
                       rd(),
                       static_cast<std::seed_seq::result_type>(
                           timePoint.time_since_epoch().count())};
    return std::mt19937{seed};
  }

  inline std::mt19937 mt{generate()};

  template <typename T>
  inline T distribution(T min, T max) {
    static_assert(std::is_integral_v<T>, "T must be an integral type");
    return std::uniform_int_distribution<T>(min,max)(mt);
  }
}  // namespace Random
