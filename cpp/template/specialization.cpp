#include <cmath>
#include <iostream>

template <typename T>
bool equal(T a, T b) {
  return (a == b);
}

template <>
bool equal<float>(float a, float b) {
  std::cout << "equal<flat>\n";
  return fabs(a - b) < 0.00001f;
}

template <typename T, typename C>
auto multiply(const T &a, const C &b) -> decltype(a * b) {
  return a * b;
}

int main() {
  std::cout << equal(2, 2) << '\n';
  std::cout << equal(1.0f - 0.999999f, 0.000001f) << '\n';
  std::cout << multiply(10, 34.3) << '\n';
  return 0;
}