#include "header.h"
template <typename T1, typename T2, typename T3> T1 sum(T2 left, T3 right) {
  return left + right;
}

template <typename T1, typename T2, typename T3>
T3 sum_trail(T2 left, T1 right) {
  return left + right;
}

int main() {
  auto val = sum<long long>(10, 234l);
  std::cout << val << std::endl;

  auto val_trail = sum_trail<long long, int, long>(10, 234l);
  std::cout << val_trail << std::endl;
  return 0;
}
