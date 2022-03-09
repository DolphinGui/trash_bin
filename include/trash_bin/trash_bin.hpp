#pragma once
#include <any>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

namespace bin {
inline void nulldestructor() noexcept {};

class trash_bin {
  struct rubbish {
    ~rubbish() = default;
  };

  template <typename T> struct impl final : rubbish { T member; };

  static decltype(auto) crumple(auto &&trash) {
    using T = std::decay_t<decltype(trash)>;
    return impl<std::unique_ptr<T>>{
        .member = std::make_unique<T>(std::forward<T>(trash))};
  }
  std::vector<rubbish> bin;

public:
  void inline reserve(size_t size) noexcept { bin.reserve(size); }
  template <typename T> void toss(T &&trash) {
    bin.push_back(crumple(std::forward<T>(trash)));
  }
  template <typename T, typename... Ts> void toss(T trash, Ts &&...more_trash) {
    toss(std::forward<T>(trash));
    toss(std::forward<Ts>(more_trash)...);
  }

  void clean() { bin.clear(); }
};
} // namespace bin