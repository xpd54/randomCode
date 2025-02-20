#include <iostream>
using namespace std;

template <typename T>
T square(T input) {
  return input * input;
}

// c++20 abbreviated function templates, Can use auto in function for c++20
auto square2(auto input) { return input * input; }
int main() {
  cout << square(3.3) << '\n';
  cout << square2(5) << '\n';
}