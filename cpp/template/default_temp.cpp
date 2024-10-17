#include "header.h"

template <typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
  if (f(v1, v2))
    return -1;
  if (f(v2, v1))
    return 1;
  return 0;
}

int main() {
  auto less = [](int v1, int v2) { return v1 > v2; };

  int value1 = 20;
  int value2 = 230;
  std::cout << compare(20, 230, less) << std::endl;
  return 0;
}
