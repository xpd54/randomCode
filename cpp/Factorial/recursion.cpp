#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
uint64_t factorial(uint64_t value) {
  if (value == 1) {
    return 1;
  }
  return value * factorial(value - 1);
}

int main() {
  std::vector<uint64_t> input;
  input.reserve(10);
  for (std::size_t i = 0; i < 10; ++i)
    input.push_back(1 + (rand() % 9));

  for (auto &value : input) {
    value = factorial(value);
  }

  std::for_each(input.begin(), input.end(),
                [](uint64_t &value) { std::cout << value << '\n'; });
  return 0;
}