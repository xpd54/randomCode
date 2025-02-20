#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
T square(T input) {
  return input * input;
}

// c++20 abbreviated function templates, Can use auto in function for c++20
auto square2(auto input) { return input * input; }

template <typename T, typename C>
void foo(T input1, C input2) {
  cout << input1 << '\n';
  cout << input2 << '\n';
}

// Non object parameter <object type, non object>
template <typename T, size_t N>
void print_time(T input) {
  for (size_t i = 0; i < N; ++i) cout << input << '\n';
}
int main() {
  cout << square(3.3) << '\n';
  cout << square2(5) << '\n';

  foo(5, 3.14f);
  print_time<string, 4>("hello");
  print_time<string, 2>("world");
}