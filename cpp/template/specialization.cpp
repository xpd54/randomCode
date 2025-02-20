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

int main() {
  std::cout << equal(2, 2) << '\n';
  std::cout << equal(1.0f - 0.999999f, 0.000001f) << '\n';
  return 0;
}