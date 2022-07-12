#include "trash_bin/trash_bin.hpp"
#include <iostream>
#include <memory>

struct object {
  int i;
  object(int a) : i(a) {}
  object(object &&other) {
    i = other.i;
    other.i = 0;
  }
  ~object() { std::cout << i << " object destroyed\n"; }
};

struct object2 {
  int i;
  object2(int a) : i(a) {}
  object2(object2 &&other) {
    i = other.i;
    other.i = 0;
  }
  ~object2() {
    if (i != 0)
      std::cout << i << " object2 destroyed\n";
  }
};

int main() {
  bin::trash_bin bin;

  {
    auto a = object(1);
    auto b = object(2);
    auto c = object(3);
    auto d = object2(1);
    auto e = object2(2);
    auto f = new object(4);
    auto g = new object2(3);
    bin.reserve(3);
    bin.toss(std::move(a), std::move(b), std::move(c));
    bin.toss(f);
    bin.toss(g);
  }
  std::cout << bin.amount() << '\n';
  std::cout << "emptying trash\n";
  bin.empty();
  std::cout << bin.amount() << '\n';
}