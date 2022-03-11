#pragma once
#include <any>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

namespace bin {

class trash_bin {
  struct rubbish {
    virtual ~rubbish() = default;
  };

  template <typename T> struct impl final : rubbish {
    impl(T &&trash) : member(std::move(trash)) {}
    impl(impl &&other) { std::swap(this->member, other.member); }
    T member;
  };
  std::vector<std::unique_ptr<rubbish>> bin;

public:
  void inline reserve(size_t size) { bin.reserve(size); }
  template <typename T> void toss(T &&trash) {
    bin.emplace_back(std::make_unique<impl<T>>(std::forward<T>(trash)));
  }
  template <typename T, typename... Ts>
  void toss(T &&trash, Ts &&...more_trash) {
    toss(std::forward<T>(trash));
    toss(std::forward<Ts>(more_trash)...);
  }
  size_t amount() const noexcept { return bin.size(); }
  void empty() { bin.clear(); }
};
} // namespace bin