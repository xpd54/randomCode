#include "usingFunction.h"
#include <iostream>
#include <vector>
int main() {
  for (int i = 0; i < 10; ++i)
    std::cout << count_calling() << "\n";
  return 0;
}