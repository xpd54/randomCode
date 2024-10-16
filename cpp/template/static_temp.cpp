#include "header.h"

template <typename T> class Foo {
public:
  static std::size_t count() { return ctr; }

private:
  static std::size_t ctr;
};

template <typename T> size_t Foo<T>::ctr = 10;

int main() {
  Foo<int> foo1, foo2;
  std::cout << foo1.count() << " " << foo2.count() << std::endl;
  Foo<int> string_foo, string_foo2;
  std::cout << string_foo.count() << " " << string_foo.count() << std::endl;
  return 0;
}
