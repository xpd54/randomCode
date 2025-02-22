#include <cstddef>
#include <iostream>
using namespace std;
template <typename T>
class Foo {
 public:
  static std::size_t get_count() { return count; }

 private:
  static size_t count;
};

template <typename T>
size_t Foo<T>::count = 10;

int main() {
  Foo<int> val;
  cout << val.get_count() << '\n';
}