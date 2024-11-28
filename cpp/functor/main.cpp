#include <algorithm>
#include <iostream>
#include <vector>

struct Add_x {
  Add_x(int value) : base(value) {}
  int base;
  int operator()(int rhs) { return base + rhs; }
};

int main() {
  std::vector<int> holding = {1, 2, 3, 4, 5, 6, 7};
  Add_x add_10(10);
  std::vector<int> output(holding.size());
  std::transform(holding.begin(), holding.end(), output.begin(), add_10);
  std::cout << "Adding 10 in each" << '\n';
  for (auto &value : output) std::cout << value << '\n';

  std::cout << "Adding 1 in each" << '\n';
  std::transform(holding.begin(), holding.end(), output.begin(), Add_x(1));
  for (auto &value : output) std::cout << value << '\n';
  return 0;
}