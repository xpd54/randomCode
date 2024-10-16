#include <iostream>
#include <string>
template <typename> class Bar;
template <typename T> class Foo {
public:
  void print(const Bar<T> &bar) { std::cout << bar.value << std::endl; }
};

template <typename T> class Bar {
  friend T;

private:
  std::string value = "hello world";
};

int main() {
  Foo<std::string> foo;
  Bar<Foo> bar;
  foo.print(bar);
  return 0;
}
