#include "trash_bin/trash_bin.hpp"
#include <iostream>
#include <memory>

struct object {
  int i;
  object(int a) : i(a) {}

  ~object() { std::cout << i << " object destroyed\n"; }
};

int main() {
  bin::trash_bin bin;
  {
    auto a = std::make_unique<object>(1);
    auto b = std::make_unique<object>(2);
    auto c = std::make_unique<object>(2);
    bin.reserve(3);
    bin.toss(std::move(a), std::move(b), std::move(c));
  }
  std::cout << "emptying trash\n";
  bin.clean();
}