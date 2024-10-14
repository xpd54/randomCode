#include <iostream>
#include <vector>
int main() {
  std::vector<int> value;
  value.push_back(10);
  auto it = value.rbegin();
  std::cout << *it << std::endl;
  return 1;
}
